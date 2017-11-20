---
title: "-utf-8 (Definir origem e executável caractere conjuntos para UTF-8) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /utf-8
dev_langs: C++
helpviewer_keywords: /utf-8 compiler option
ms.assetid: f0e1f3cb-6cae-46eb-9483-04ed13d9b504
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: d1f5d48006fff5166fff6fa559323a96997c9ed4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="utf-8-set-source-and-executable-character-sets-to-utf-8"></a>/UTF-8 (Definir origem e o executável conjuntos de caracteres UTF-8)
Especifica o conjunto de caracteres de origem e o caractere de execução definida como UTF-8.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/utf-8  
```  
  
## <a name="remarks"></a>Comentários  
 Você pode usar o **/utf-8** opção para especificar conjuntos de caracteres de origem e de execução, como codificado com UTF-8. É equivalente a especificar **/origem-charset:utf-/execution 8-charset:utf-8** na linha de comando. Além disso, qualquer uma dessas opções permite que o **/validate-charset** opção por padrão. Para obter uma lista de identificadores de página de código de suporte e os nomes do conjunto de caracteres, consulte [identificadores de página de código](http://msdn.microsoft.com/library/windows/desktop/dd317756).  
  
 Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato codificado de Unicode, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ele pressupõe que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você especificou uma página de código usando **/utf-8** ou **/source-charset** opção. O Visual Studio permite que você salve seu código-fonte C++ usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets2.md) na documentação do idioma.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração**, **C/C++**, **linha de comando** pasta.  
  
3.  Em **opções avançadas de**, adicione o **/utf-8** opção e especifique a codificação preferencial.  
  
4.  Escolha **Okey** para salvar suas alterações.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [/Execution-charset (defina a execução do conjunto de caracteres)](../../build/reference/execution-charset-set-execution-character-set.md)   
 [/Source-charset (definir fonte do conjunto de caracteres)](../../build/reference/source-charset-set-source-character-set.md)   
 [/Validate-charset (validar caracteres compatível)](../../build/reference/validate-charset-validate-for-compatible-characters.md)