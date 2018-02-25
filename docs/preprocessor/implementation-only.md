---
title: implementation_only | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- implementation_only
dev_langs:
- C++
helpviewer_keywords:
- implementation_only attribute
ms.assetid: d8cabc86-4425-45a0-9587-d57536980088
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: aa9fe0e8bf3cdecbdf118219cfe91be03a85a51f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="implementationonly"></a>implementation_only
**Específicas do C++**  
  
 Suprime geração do arquivo de cabeçalho .tlh (o arquivo de cabeçalho primário).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
implementation_only  
```  
  
## <a name="remarks"></a>Comentários  
 Esse arquivo contém todas as declarações usadas para expor o conteúdo da biblioteca de tipos. O arquivo de cabeçalho .tli, com as implementações de funções membro de wrapper, será gerado e incluído na compilação.  
  
 Quando esse atributo é especificado, o conteúdo do cabeçalho .tli está no mesmo namespace do geralmente usado no cabeçalho .tlh. Além disso, as funções membro não são declaradas como embutidas.  
  
 O `implementation_only` atributo destina-se ao uso em conjunto com o [no_implementation](../preprocessor/no-implementation.md) atributo como uma maneira de manter as implementações fora do arquivo de cabeçalho pré-compilado (PCH). Uma instrução `#import` com o atributo `no_implementation` é colocada na região de origem usada para criar o PCH. O PCH resultante é usado por diversos arquivos de origem. Uma instrução `#import` com o atributo de `implementation_only` é então usada fora da região de PCH. É necessário usar essa instrução somente uma vez em um dos arquivos de origem. Isso gerará todas as funções membro de wrapper necessárias, sem recompilação adicional para cada arquivo de origem.  
  
> [!NOTE]
>  O atributo `implementation_only` em uma instrução `#import` deve ser usado junto à outra instrução `#import`, da mesma biblioteca de tipo, com o atributo `no_implementation`. Caso contrário, serão gerados erros do compilador. Isso ocorre porque as definições da classe wrapper, geradas pela instrução `#import` com o atributo `no_implementation`, são necessárias para compilar as implementações geradas pelo atributo `implementation_only`.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)