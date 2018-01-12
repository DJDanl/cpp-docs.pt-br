---
title: RW2001 de erro do compilador de recurso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: RW2001
dev_langs: C++
helpviewer_keywords: RW2001
ms.assetid: 963bdc7d-6ebe-4378-8bbc-47dfcf5d330c
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1a14cd36ab87297cf5bc0aa547bdea5ef23260e8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-compiler-error-rw2001"></a>Erro RW2001 (compilador de recurso)
Diretiva inválida no arquivo RC pré-processados  
  
 O arquivo RC contém um **#pragma** diretiva.  
  
 Use o **#ifndef** diretiva de pré-processamento com o **RC_INVOKED** constante que o compilador de recurso define quando ele processa um arquivo de inclusão. Local de **#pragma** diretiva dentro de um bloco de código que não é processada quando a **RC_INVOKED** constante é definida. Código do bloco é processado somente pelo compilador C/C++ e não pelo compilador de recurso. O código de exemplo a seguir demonstra essa técnica:  
  
```  
#ifndef RC_INVOKED  
#pragma pack(2)  // C/C++ only, ignored by Resource Compiler  
#endif  
```  
  
 O **#pragma** diretiva de pré-processamento não tem nenhum significado um. Arquivo RC. O **#include** diretiva de pré-processamento é usada frequentemente em uma. Arquivo RC para incluir um arquivo de cabeçalho (um arquivo de cabeçalho personalizado baseado no projeto ou um arquivo de cabeçalho padrão fornecido pela Microsoft com um de seus produtos). Eles incluem arquivos contêm o **#pragma** diretiva. Como um arquivo de cabeçalho pode incluir um ou mais outros arquivos de cabeçalho, o arquivo que contém a cadeia de **#pragma** diretiva não pode ser imediatamente óbvia.  
  
 O **#ifndef RC_INVOKED** técnica pode controlar, incluindo arquivos de cabeçalho em arquivos de cabeçalho baseada em projeto.