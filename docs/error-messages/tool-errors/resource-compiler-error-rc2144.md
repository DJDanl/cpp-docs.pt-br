---
title: Erro RC2144 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC2144
helpviewer_keywords:
- RC2144
ms.assetid: 1b3ff39a-92cd-4a04-b1a3-b1fa6a805813
ms.openlocfilehash: 1b080916642fc1be4b22820668c4cb4137675425
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80191191"
---
# <a name="resource-compiler-error-rc2144"></a>Erro RC2144 (compilador de recurso)

ID DE IDIOMA PRIMÁRIO não é um número

A ID DE IDIOMA PRIMÁRIO deve ser uma ID de idioma hexadecimal. Consulte [cadeias de caracteres de idioma e país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md) na *referência da biblioteca de tempo de execução* para obter uma lista de IDs de idioma válidas.

Esse erro também pode ocorrer se os recursos forem adicionados e excluídos do arquivo .RC usando uma ferramenta. Para corrigir esse problema, abra o arquivo .RC em um editor de texto e limpe quaisquer recursos não usados manualmente.
