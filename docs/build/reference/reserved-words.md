---
title: Palavras reservadas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- code
- CONFORMING
- DISCARDABLE
- Description
- base
- APPLOADER
- Data
- DYNAMIC
- DEV386
dev_langs: C++
helpviewer_keywords:
- .def files [C++], reserved words
- def files [C++], reserved words
- linker [C++], reserved words
- reserved words [C++]
ms.assetid: 9b9f49e5-0739-45ab-a37e-81e3915ceb25
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 35f9a3e907b72b4b8cf8e673e771832ba3fc0527
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="reserved-words"></a>Palavras reservadas
As seguintes palavras são reservadas pelo vinculador. Esses nomes podem ser usados como argumentos em [instruções de definição de módulo](../../build/reference/module-definition-dot-def-files.md) somente se o nome é colocado entre aspas duplas ("").  
  
||||  
|-|-|-|  
|**APPLOADER**1|**INITINSTANCE**2|**PRÉ-CARREGAMENTO**|  
|**BASE**|**IOPL**|**PRIVADA**|  
|**CÓDIGO**|**BIBLIOTECA**1|**PROTMODE**2|  
|**EM CONFORMIDADE**|**LOADONCALL**1|**PURO**1|  
|**DADOS**|**LONGNAMES**2|**SOMENTE LEITURA**|  
|**DESCRIÇÃO**|**PODEM SER MOVIDOS**1|**READWRITE**|  
|**DEV386**|**MOVEABLE**1|**MODO REAL**1|  
|**DESCARTÁVEIS**|**VÁRIOS**|**RESIDENTE**|  
|**DINÂMICO**|**NOME**|**RESIDENTNAME**1|  
|**SOMENTE PARA EXECUÇÃO**|**NEWFILES**2|**SEÇÕES**|  
|**EXECUTEONLY**|**NODATA**1|**SEGMENTOS**|  
|**EXECUTEREAD**|**NOIOPL**1|**COMPARTILHADO**|  
|**EXETYPE**|**SEM NOME**|**ÚNICO**|  
|**EXPORTS**|**NÃO CONFORMES**1|**STACKSIZE**|  
|**FIXA**1|**NONDISCARDABLE**|**STUB**|  
|**FUNÇÕES**2|**NENHUM**|**VERSÃO**|  
|**HEAPSIZE**|**NÃO COMPARTILHADO**|**WINDOWAPI**|  
|**IMPORTAÇÕES**|**NOTWINDOWCOMPAT**1|**WINDOWCOMPAT**|  
|**IMPUROS**1|**OBJETOS**|**WINDOWS**|  
|**INCLUIR**2|**ANTIGO**1||  
  
 1 o vinculador emite um aviso ("ignorado") quando ele encontra esse termo. No entanto, a palavra é preservada.  
  
 2 o vinculador ignora essa palavra mas emite sem aviso.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)