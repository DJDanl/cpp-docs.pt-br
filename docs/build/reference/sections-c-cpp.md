---
title: SEÇÕES (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- SECTIONS
dev_langs:
- C++
helpviewer_keywords:
- SECTIONS .def file statement
ms.assetid: 7b974366-9ef5-4e57-bbcc-73a1df6f8857
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0ab2f021a53e8ae685891863500feb3873e13e2e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
 `SECTIONS`marca o início de uma lista de seção `definitions`. Cada `definition` devem estar em uma linha separada. O `SECTIONS` palavra-chave pode estar na mesma linha como o primeiro `definition` ou em uma linha anterior. O arquivo. def pode conter um ou mais `SECTIONS` instruções. O `SEGMENTS` palavra-chave é suportado como um sinônimo para `SECTIONS`.  
  
 Suporte para versões mais antigas do Visual C++:  
  
```  
section [CLASS 'classname'] specifier  
```  
  
 O `CLASS` palavra-chave é suportada para compatibilidade, mas é ignorado.  
  
 É uma maneira equivalente para especificar atributos de seção com o [/seção](../../build/reference/section-specify-section-attributes.md) opção.  
  
## <a name="see-also"></a>Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)