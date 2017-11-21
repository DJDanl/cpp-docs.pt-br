---
title: runtime_checks | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc-pragma.runtime_checks
- runtime_checks_CPP
dev_langs: C++
helpviewer_keywords:
- runtime_checks pragma
- pragmas, runtime_checks
ms.assetid: ae50b43f-f88d-47ad-a2db-3389e9e7df5b
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ee68bfc7ddace32432f64d4325d9a4c669e0819b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="runtimechecks"></a>runtime_checks
Desabilita ou restaura o [/RTC](../build/reference/rtc-run-time-error-checks.md) configurações.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma runtime_checks( "[runtime_checks]", {restore | off} )  
```  
  
## <a name="remarks"></a>Comentários  
 Não é possível habilitar uma verificação de tempo de execução que não foi habilitada com uma opção de compilador. Por exemplo, se você não especificar /RTCs, especificar `#pragma runtime_checks( "s", restore)` não habilitará a verificação do registro de ativação.  
  
 O **runtime_checks** pragma deve aparecer fora de uma função e entra em vigor na primeira função definida após o pragma é visto. O **restaurar** e **off** argumentos ativar opções especificadas a *runtime_checks* ativado ou desativado.  
  
 O *runtime_checks* pode ser zero ou mais dos parâmetros mostrados na tabela a seguir.  
  
### <a name="parameters-of-the-runtimechecks-pragma"></a>Parâmetros do pragma runtime_checks  
  
|Parâmetro(s)|Tipo de verificação de tempo de execução|  
|--------------------|-----------------------------|  
|**s**|Habilita a verificação de (registro de) pilha.|  
|**c**|Informa quando um valor é atribuído a um tipo de dados menor que resulta em uma perda de dados.|  
|**u**|Informa quando uma variável é usada antes de ser definida.|  
  
 Essas são as mesmas letras usadas com a opção de compilador /RTC. Por exemplo:  
  
```  
#pragma runtime_checks( "sc", restore )  
```  
  
 Usando o **runtime_checks** pragma com a cadeia de caracteres vazia (**""**) é uma forma especial da diretiva:  
  
-   Quando você usa o **off** parâmetro, ele transforma as verificações de erro de tempo de execução, listadas na tabela acima, off.  
  
-   Quando você usa o **restaurar** parâmetro, ele redefine as verificações de erro de tempo de execução para aqueles que você especificou com a opção de compilador /RTC.  
  
```  
#pragma runtime_checks( "", off )  
.  
.  
.  
#pragma runtime_checks( "", restore )   
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)   
