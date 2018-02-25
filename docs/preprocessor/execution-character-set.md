---
title: execution_character_set | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- execution_character_set
- vc-pragma.execution_character_set
dev_langs:
- C++
helpviewer_keywords:
- pragma execution_character_set
ms.assetid: 32248cbc-7c92-4dca-8442-230c052b53ad
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: eda04de6975708b2460e53681e50f8ea4f9dbcd3
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="executioncharacterset"></a>execution_character_set
Especifica o conjunto de caracteres de execução usado para literais de cadeia de caracteres e caracteres. Essa diretiva não é necessária para literais marcados com o prefixo u8.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma execution_character_set("target")  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `target`  
 Especifica o conjunto de caracteres de execução de destino. Atualmente, a execução de destino somente definida com suporte é "utf-8".  
  
## <a name="remarks"></a>Comentários  
 Essa diretiva de compilador é obsoleta a partir do Visual Studio 2015 atualização 2. Recomendamos que você use o **/execution-charset:utf-8** ou **/utf-8** opções do compilador junto com usando o `u8` prefixo em estreita caracteres e cadeia de caracteres literais que contêm estendido caracteres. Para obter mais informações sobre o `u8` prefixo, consulte [cadeia de caracteres e literais de caracteres](../cpp/string-and-character-literals-cpp.md). Para obter mais informações sobre as opções do compilador, consulte [/execution-charset (defina a execução do conjunto de caracteres)](../build/reference/execution-charset-set-execution-character-set.md) e [/utf-8 (Definir origem e executável caractere conjuntos para UTF-8)](../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md).  
  
 O `#pragma execution_character_set("utf-8")` diretiva informa ao compilador para codificar caracteres estreita e literais de cadeia de caracteres específica em seu código-fonte como UTF-8 no executável. Essa codificação de saída é independente da codificação do arquivo de origem usado.  
  
 Por padrão, o compilador codifica caracteres estreitas e cadeias de caracteres específica por meio da página de código atual como o conjunto de caracteres de execução. Isso significa que caracteres Unicode ou DBCS em um literal que estão fora do intervalo de página de código atual são convertidos para o caractere de substituição padrão na saída. Caracteres Unicode e DBCS é truncado para o byte de ordem inferior. Isso é certamente não o que você pretende. Você pode especificar a codificação UTF-8 para literais no arquivo de origem usando um `u8` prefixo. O compilador passa essas cadeias de caracteres codificada em UTF-8 para a saída inalteradas. Literais de caracteres estreita prefixados usando u8 devem se ajustar em um byte, ou eles são truncados na saída.  
  
 Por padrão, o Visual Studio usa a página de código atual como o conjunto de caracteres de origem usado para interpretar o código-fonte para a saída. Quando um arquivo é lido, o Visual Studio o interpreta de acordo com a página de código atual, a menos que a página de código do arquivo foi definida ou se uma marca de ordem de byte (BOM) ou caracteres UTF-16 são detectados no início do arquivo. Como UTF-8 não pode ser definida como a página de código atual, quando a detecção automática encontra os arquivos de origem codificados como UTF-8 sem um BOM, o Visual Studio pressupõe que eles são codificados usando a página de código atual. Caracteres no arquivo de origem que estão fora do intervalo especificado ou automaticamente detectados página de código pode causar erros e avisos do compilador.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas pragma e a palavra-chave pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)   
 [/Execution-charset (defina a execução do conjunto de caracteres)](../build/reference/execution-charset-set-execution-character-set.md)   
 [/utf-8 (definir conjuntos de caracteres de origem e executáveis como UTF-8)](../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md)