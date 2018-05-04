---
title: -vmb, - /vmg (método de representação) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /vmb
- /vmg
dev_langs:
- C++
helpviewer_keywords:
- vmb compiler option [C++]
- -vmg compiler option [C++]
- vmg compiler option [C++]
- -vmb compiler option [C++]
- /vmb compiler option [C++]
- representation method compiler options [C++]
- /vmg compiler option [C++]
ms.assetid: ecdb391c-7dab-40b1-916b-673d10889fd4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5263b6c7ca227a10b34c32e0b0801eeddf07b9cd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="vmb-vmg-representation-method"></a>/vmb, /vmg (método de representação)
Selecione o método que o compilador usa para representar ponteiros para membros de classe.  
  
 Use **/vmb** se sempre definir uma classe antes de declarar um ponteiro para um membro da classe.  
  
 Use **/vmg** para declarar um ponteiro para um membro de uma classe antes de definir a classe. Essa necessidade pode surgir se você definir os membros de duas classes diferentes que referenciam uns aos outros. Para essas classes de referência mutuamente, uma classe deve ser referenciada antes de ser definida.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/vmb  
/vmg  
```  
  
## <a name="remarks"></a>Comentários  
 Você também pode usar [pointers_to_members](../../preprocessor/pointers-to-members.md) ou [palavras-chave de herança](../../cpp/inheritance-keywords.md) em seu código para especificar uma representação de ponteiro.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)