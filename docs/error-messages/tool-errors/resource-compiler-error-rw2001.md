---
title: RW2001 de erro do compilador de recurso | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RW2001
dev_langs:
- C++
helpviewer_keywords:
- RW2001
ms.assetid: 963bdc7d-6ebe-4378-8bbc-47dfcf5d330c
caps.latest.revision: 6
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
ms.openlocfilehash: dca4d021b950ff142aeb7752d1f6cdb9ddd4e149
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-error-rw2001"></a>Erro RW2001 (compilador de recurso)
Diretiva inválida no arquivo RC pré-processado  
  
 O arquivo RC contém um **#pragma** diretiva.  
  
 Use o **#ifndef** diretiva de pré-processador com o **RC_INVOKED** constante que o compilador de recurso define quando ele processa um arquivo de inclusão. Local de **#pragma** diretiva dentro de um bloco de código que não é processado quando o **RC_INVOKED** constante é definida. Código do bloco é processado apenas pelo compilador C/C++ e não pelo compilador de recurso. O código de exemplo a seguir demonstra essa técnica:  
  
```  
#ifndef RC_INVOKED  
#pragma pack(2)  // C/C++ only, ignored by Resource Compiler  
#endif  
```  
  
 O **#pragma** diretiva de pré-processador não tem nenhum significado um. Arquivo RC. O **#include** diretiva de pré-processamento é usada frequentemente em um. Arquivo RC para incluir um arquivo de cabeçalho (um arquivo de cabeçalho personalizado baseado no projeto ou um arquivo de cabeçalho padrão fornecido pela Microsoft com um de seus produtos). Alguns deles incluem arquivos contêm o **#pragma** diretiva. Como um arquivo de cabeçalho pode incluir um ou mais outros arquivos de cabeçalho, o arquivo que contém o ofensivos **#pragma** diretiva pode não ser imediatamente óbvia.  
  
 O **#ifndef RC_INVOKED** técnica pode controlar, incluindo arquivos de cabeçalho em arquivos de cabeçalho com base em projeto.
