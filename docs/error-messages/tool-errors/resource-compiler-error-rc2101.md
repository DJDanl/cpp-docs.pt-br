---
title: RC2101 de erro do compilador de recurso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: RC2101
dev_langs: C++
helpviewer_keywords: RC2101
ms.assetid: 580f9d74-162f-41e9-9438-ddbe3457c359
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d08e9ddb7b8cda127b1d05bfef52b52833534cb2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-compiler-error-rc2101"></a>Erro RC2101 (compilador de recurso)
Diretiva inválida no arquivo RC pré-processados  
  
 O arquivo de compilador de recurso contém um **#pragma** diretiva.  
  
 Use o **#ifndef** diretiva de pré-processador com a constante RC_INVOKED que o compilador de recurso define quando ele processa um arquivo de inclusão. Coloque o **#pragma** diretiva dentro de um bloco de código que não é processado quando a constante RC_INVOKED está definida. Código do bloco é processado somente pelo compilador C/C++ e não pelo compilador de recurso. O código de exemplo a seguir demonstra essa técnica:  
  
```  
#ifndef RC_INVOKED  
#pragma pack(2)  // C/C++ only, ignored by Resource Compiler  
#endif  
```  
  
 O **#pragma** diretiva de pré-processamento não tem nenhum significado um. Arquivo RC. O **#include** diretiva de pré-processamento é usada frequentemente em uma. Arquivo RC para incluir um arquivo de cabeçalho (um arquivo de cabeçalho personalizado baseado no projeto ou um arquivo de cabeçalho padrão fornecido pela Microsoft com um de seus produtos). Eles incluem arquivos contêm o **#pragma** diretiva. Como um arquivo de cabeçalho pode incluir um ou mais outros arquivos de cabeçalho, o arquivo que contém a cadeia de **#pragma** diretiva não pode ser imediatamente óbvia.  
  
 O **#ifndef** técnica RC_INVOKED pode controlar, incluindo arquivos de cabeçalho em arquivos de cabeçalho baseada em projeto.