---
title: RC2144 de erro do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC2144
dev_langs:
- C++
helpviewer_keywords:
- RC2144
ms.assetid: 1b3ff39a-92cd-4a04-b1a3-b1fa6a805813
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8b6f83f937e881cdee16c22120e6ac1839f7ad76
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33320480"
---
# <a name="resource-compiler-error-rc2144"></a>Erro RC2144 (compilador de recurso)
ID DE IDIOMA PRIMÁRIO não é um número  
  
 A ID DE IDIOMA PRIMÁRIO deve ser uma ID de idioma hexadecimal. Consulte [cadeias de caracteres de país/região e idioma](../../c-runtime-library/locale-names-languages-and-country-region-strings.md) no *referência da biblioteca de tempo de execução* para obter uma lista de IDs de idioma válido.  
  
 Esse erro também pode ocorrer se os recursos forem adicionados e excluídos do arquivo .RC usando uma ferramenta. Para corrigir esse problema, abra o arquivo .RC em um editor de texto e limpe quaisquer recursos não usados manualmente.