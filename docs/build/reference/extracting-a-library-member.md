---
title: Extraindo um membro da biblioteca | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: Lib
dev_langs: C++
helpviewer_keywords:
- LIB [C++], extracting library members
- EXTRACT library manager option
- libraries, extracting members
- -EXTRACT library manager option
- extracting library members
- /EXTRACT library manager option
ms.assetid: a2c5c2a1-9b7e-489a-a9a4-1dec694e1fc5
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1c27e5c78316ec48d114bfd1715eb5874772a732
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="extracting-a-library-member"></a>Extraindo um membro da biblioteca
Você pode usar a biblioteca para criar um arquivo de objeto (. obj) que contenha uma cópia de um membro de uma biblioteca existente. Para extrair uma cópia de um membro, use a seguinte sintaxe:  
  
```  
LIB library /EXTRACT:member /OUT:objectfile  
```  
  
 Este comando cria um arquivo. obj chamado *objectfile* que contém uma cópia de um `member` de um *biblioteca*. O `member` nome diferencia maiusculas de minúsculas. Você pode extrair somente um membro em um único comando. A opção /OUT é obrigatória. Não há nenhum nome de saída padrão. Se um arquivo chamado *objectfile* já existe no diretório especificado (ou o diretório atual, se nenhuma pasta for especificada com *objectfile*), o *objectfile*substitui o arquivo existente.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de LIB](../../build/reference/lib-reference.md)