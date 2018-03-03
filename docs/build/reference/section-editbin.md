---
title: "-SEÇÃO (EDITBIN) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /section
dev_langs:
- C++
helpviewer_keywords:
- -SECTION editbin option
- SECTION editbin option
- alignment characters in sections
- /SECTION editbin option
ms.assetid: 4680ab4e-c984-4251-8241-93440cad7615
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 91ffb9bd0645cab51e4140697c41e5b715380fe8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="section-editbin"></a>/SECTION (EDITBIN)
```  
/SECTION:name[=newname][,attributes][alignment]  
```  
  
## <a name="remarks"></a>Comentários  
 Esta opção altera os atributos de uma seção, sobrescrevendo os atributos que foram definidos quando o arquivo de objeto para a seção foi compilado ou vinculado.  
  
 Após os dois-pontos ( **:** ), especifique o *nome* da seção. Para alterar o nome da seção, execute *nome* com um sinal de igual (=) e um *newname* da seção.  
  
 Para definir ou alterar a seção `attributes`, especifique uma vírgula (**,**) seguido por um ou mais caracteres de atributos. Para negar um atributo, preceda seu caractere com um ponto de exclamação (!). Os seguintes caracteres especificam atributos de memória:  
  
|Atributo|Configuração|  
|---------------|-------------|  
|c|código|  
|d|Descartáveis|  
|e|executável|  
|i|dados inicializados|  
|K|memória virtual em cache|  
|m|Remover link|  
|o|informações de link|  
|p|memória virtual paginável|  
|R|read|  
|s|shared|  
|u|dados não inicializados|  
|W|write|  
  
 Para controlar *alinhamento*, especifique o caractere **um** seguido por um dos caracteres a seguir para definir o tamanho de alinhamento em bytes, da seguinte maneira:  
  
|Caractere|Tamanho de alinhamento em bytes|  
|---------------|-----------------------------|  
|1|1|  
|2|2|  
|4|4|  
|8|8|  
|p|16|  
|t|32|  
|s|64|  
|x|Nenhum alinhamento|  
  
 Especifique o `attributes` e *alinhamento* caracteres como uma cadeia de caracteres com nenhum espaço em branco. Os caracteres não diferenciam maiusculas de minúsculas.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de EDITBIN](../../build/reference/editbin-options.md)