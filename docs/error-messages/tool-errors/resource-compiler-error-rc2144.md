---
title: Erro RC2144 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC2144
helpviewer_keywords:
- RC2144
ms.assetid: 1b3ff39a-92cd-4a04-b1a3-b1fa6a805813
ms.openlocfilehash: deabd639e04d5b78b398cda9245e9726e2124740
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62173464"
---
# <a name="resource-compiler-error-rc2144"></a>Erro RC2144 (compilador de recurso)

ID DE IDIOMA PRIMÁRIO não é um número

A ID DE IDIOMA PRIMÁRIO deve ser uma ID de idioma hexadecimal. Ver [cadeias de caracteres de país/região e idioma](../../c-runtime-library/locale-names-languages-and-country-region-strings.md) na *referência de biblioteca de tempo de execução* para obter uma lista de IDs de idioma válido.

Esse erro também pode ocorrer se os recursos forem adicionados e excluídos do arquivo .RC usando uma ferramenta. Para corrigir esse problema, abra o arquivo .RC em um editor de texto e limpe quaisquer recursos não usados manualmente.