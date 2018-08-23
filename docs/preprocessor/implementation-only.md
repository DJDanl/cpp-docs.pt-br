---
title: implementation_only | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- implementation_only
dev_langs:
- C++
helpviewer_keywords:
- implementation_only attribute
ms.assetid: d8cabc86-4425-45a0-9587-d57536980088
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2e7f0f40ad5d01b647f1f3273dc9a55d7cfa7564
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42538199"
---
# <a name="implementationonly"></a>implementation_only
**Específico do C++**  
  
Suprime geração do arquivo de cabeçalho .tlh (o arquivo de cabeçalho primário).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
implementation_only  
```  
  
## <a name="remarks"></a>Comentários  
 
Esse arquivo contém todas as declarações usadas para expor o conteúdo da biblioteca de tipos. O arquivo de cabeçalho .tli, com as implementações de funções membro de wrapper, será gerado e incluído na compilação.  
  
Quando esse atributo é especificado, o conteúdo do cabeçalho .tli está no mesmo namespace do geralmente usado no cabeçalho .tlh. Além disso, as funções membro não são declaradas como embutidas.  
  
O **implementation_only** atributo é destinado para uso em conjunto com o [no_implementation](../preprocessor/no-implementation.md) atributo como uma maneira de manter as implementações fora do arquivo de cabeçalho pré-compilado (PCH). Uma instrução `#import` com o atributo `no_implementation` é colocada na região de origem usada para criar o PCH. O PCH resultante é usado por diversos arquivos de origem. Uma `#import` instrução com o **implementation_only** atributo é então usado fora da região de PCH. É necessário usar essa instrução somente uma vez em um dos arquivos de origem. Isso gerará todas as funções membro de wrapper necessárias, sem recompilação adicional para cada arquivo de origem.  
  
> [!NOTE]
> O **implementation_only** atributo em uma `#import` instrução deve ser usado em conjunto com outro `#import` instrução, do mesmo tipo de biblioteca, com o `no_implementation` atributo. Caso contrário, serão gerados erros do compilador. Isso ocorre porque as definições de classe de wrapper geradas pela `#import` instrução com o `no_implementation` atributo são necessárias para compilar as implementações geradas pelo **implementation_only** atributo.  
  
**FIM de específico de C++**  
  
## <a name="see-also"></a>Consulte também  
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)