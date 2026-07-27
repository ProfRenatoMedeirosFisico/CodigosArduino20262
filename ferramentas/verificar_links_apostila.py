#!/usr/bin/env python3
"""Valida os links \codigoGitHub{...} presentes na apostila LaTeX.

Uso no Windows:
    python verificar_links_apostila.py "D:\\caminho\\apostila_arduino_Vgama.tex"
"""

from __future__ import annotations

import argparse
import re
import sys
import urllib.error
import urllib.request
from pathlib import Path

OWNER = "ProfRenatoMedeirosFisico"
REPO = "CodigosArduino20262"
BRANCH = "main"
RAW_BASE = f"https://raw.githubusercontent.com/{OWNER}/{REPO}/{BRANCH}/"

PADRAO = re.compile(r"\\codigoGitHub\s*\{\s*([^{}]+?\.ino)\s*\}", re.MULTILINE)


def verificar_url(caminho: str, timeout: float = 15.0) -> tuple[bool, str]:
    url = RAW_BASE + caminho
    req = urllib.request.Request(url, headers={"User-Agent": "ApostilaArduino-LinkChecker/1.0"})
    try:
        with urllib.request.urlopen(req, timeout=timeout) as resposta:
            if resposta.status == 200:
                return True, url
            return False, f"HTTP {resposta.status}: {url}"
    except urllib.error.HTTPError as exc:
        return False, f"HTTP {exc.code}: {url}"
    except urllib.error.URLError as exc:
        return False, f"Erro de rede: {exc.reason} — {url}"


def main() -> int:
    parser = argparse.ArgumentParser(description="Valida os códigos GitHub citados pela apostila.")
    parser.add_argument("tex", type=Path, help="arquivo .tex da apostila")
    args = parser.parse_args()

    if not args.tex.is_file():
        print(f"ERRO: arquivo não encontrado: {args.tex}", file=sys.stderr)
        return 2

    texto = args.tex.read_text(encoding="utf-8", errors="replace")
    caminhos = PADRAO.findall(texto)

    if not caminhos:
        print("Nenhuma chamada \\codigoGitHub{...} foi encontrada.")
        return 1

    duplicados = len(caminhos) - len(set(caminhos))
    falhas: list[tuple[str, str]] = []

    print(f"Arquivo: {args.tex}")
    print(f"Links encontrados: {len(caminhos)}")
    print(f"Links únicos: {len(set(caminhos))}")
    print(f"Duplicados: {duplicados}")
    print("-" * 72)

    for numero, caminho in enumerate(caminhos, start=1):
        ok, detalhe = verificar_url(caminho)
        estado = "OK" if ok else "FALHA"
        print(f"[{numero:02d}/{len(caminhos):02d}] {estado:5s}  {caminho}")
        if not ok:
            falhas.append((caminho, detalhe))

    print("-" * 72)
    print(f"Válidos: {len(caminhos) - len(falhas)}")
    print(f"Falhas:  {len(falhas)}")

    if falhas:
        print("\nDetalhes das falhas:")
        for caminho, detalhe in falhas:
            print(f"- {caminho}: {detalhe}")
        return 1

    print("\nVALIDAÇÃO CONCLUÍDA: todos os links apontam para arquivos existentes.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
