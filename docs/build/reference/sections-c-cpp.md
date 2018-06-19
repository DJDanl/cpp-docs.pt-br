---
title: SEÇÕES (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- SECTIONS
dev_langs:
- C++
helpviewer_keywords:
- SECTIONS .def file statement
ms.assetid: 7b974366-9ef5-4e57-bbcc-73a1df6f8857
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c433bf49ee4c56833ac7291bcc4a0f90e32f4e5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32377294"
---
# <a name="sections-cc"></a>SECTIONS (C/C++)
Apresenta uma seção de uma ou mais `definitions` que são especificadores de acesso sobre seções no arquivo de saída do projeto.  
  
```  
SECTIONS  
definitions  
```  
  
## <a name="remarks"></a>Comentários  
 Cada definição deve ficar em uma linha separada. O `SECTIONS` palavra-chave pode estar na mesma linha como a primeira definição ou em uma linha anterior. O arquivo. def pode conter um ou mais `SECTIONS` instruções.  
  
 Isso `SECTIONS` instrução define atributos de uma ou mais seções no arquivo de imagem e pode ser usada para substituir os atributos padrão para cada tipo de seção.  
  
 O formato para `definitions` é:  
  
 `.section_name specifier`  
  
 onde `.section_name` é o nome de uma seção em sua imagem de programa e `specifier` é um ou mais dos seguintes modificadores de acesso:  
  
|Modificador|Descrição|  
|--------------|-----------------|  
|`EXECUTE`|A seção é executável|  
|`READ`|Permite operações de leitura em dados|  
|`SHARED`|Compartilha a seção entre todos os processos que carregam a imagem|  
|`WRITE`|Permite operações de gravação de dados|  
  
 Separe os nomes de especificador com um espaço. Por exemplo:  
  
```  
SECTIONS  
.rdata READ WRITE  
```  
  
 `SECTIONS` marca o início de uma lista de seção `definitions`. Cada `definition` devem estar em uma linha separada. O `SECTIONS` palavra-chave pode estar na mesma linha como o primeiro `definition` ou em uma linha anterior. O arquivo. def pode conter um ou mais `SECTIONS` instruções. O `SEGMENTS` palavra-chave é suportado como um sinônimo para `SECTIONS`.  
  
 Suporte para versões mais antigas do Visual C++:  
  
```  
section [CLASS 'classname'] specifier  
```  
  
 O `CLASS` palavra-chave é suportada para compatibilidade, mas é ignorado.  
  
 É uma maneira equivalente para especificar atributos de seção com o [/seção](../../build/reference/section-specify-section-attributes.md) opção.  
  
## <a name="see-also"></a>Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)