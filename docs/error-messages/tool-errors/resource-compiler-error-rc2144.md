---
title: RC2144 de erro do compilador de recurso | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC2144
dev_langs:
- C++
helpviewer_keywords:
- RC2144
ms.assetid: 1b3ff39a-92cd-4a04-b1a3-b1fa6a805813
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 123f26c74278de278c6a32b2131d14d050cc193c
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-error-rc2144"></a>Erro RC2144 (compilador de recurso)
ID DE IDIOMA PRIMÁRIO não é um número  
  
 A ID DE IDIOMA PRIMÁRIO deve ser uma ID de idioma hexadecimal. Consulte [idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md) no *referência da biblioteca de tempo de execução* para obter uma lista de IDs de idioma válido.  
  
 Esse erro também pode ocorrer se os recursos forem adicionados e excluídos do arquivo .RC usando uma ferramenta. Para corrigir esse problema, abra o arquivo .RC em um editor de texto e limpe quaisquer recursos não usados manualmente.
