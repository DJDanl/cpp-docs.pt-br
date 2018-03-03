---
title: "-EXPORT (exporta uma função) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.ExportFunctions
- /export
dev_langs:
- C++
helpviewer_keywords:
- /EXPORT linker option
- EXPORT linker option
- -EXPORT linker option
ms.assetid: 0920fb44-a472-4091-a8e6-73051f494ca0
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2183a67679fc216396d03ac31a5a11db8d011454
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="export-exports-a-function"></a>/EXPORT (exporta uma função)
```  
/EXPORT:entryname[,@ordinal[,NONAME]][,DATA]  
```  
  
## <a name="remarks"></a>Comentários  
 Com essa opção, você pode exportar uma função em seu programa para que outros programas podem chamar a função. Você também pode exportar dados. Exportações geralmente são definidas em uma DLL.  
  
 O *Nome_da_entrada* é o nome do item de dados ou função como ele será usado pelo programa de chamada. `ordinal`Especifica um índice na tabela de exportações no intervalo de 1 a 65.535; Se você não especificar `ordinal`, LINK atribui um. O **NONAME** palavra-chave exporta a função apenas como um ordinal, sem um *Nome_da_entrada*.  
  
 O **dados** palavra-chave especifica que o item exportado é um item de dados. O item de dados do programa cliente deve ser declarado usando **__declspec(dllimport) extern**.  
  
 Há três métodos para exportar uma definição, listada em ordem de recomendação de uso:  
  
1.  [dllexport](../../cpp/dllexport-dllimport.md) no código-fonte  
  
2.  Um [exportações](../../build/reference/exports.md) instrução em um arquivo. def  
  
3.  Uma especificação /EXPORT em um comando LINK  
  
 Todos os três métodos podem ser usados no mesmo programa. Quando o LINK cria um programa que contém exportações, ele também cria uma biblioteca de importação, a menos que um arquivo. EXP é usado na compilação.  
  
 LINK usa decorado formulários de identificadores. O compilador decora um identificador ao criar o arquivo. obj. Se *Nome_da_entrada* é especificado para o vinculador no seu não decorado formar (conforme ele aparece no código-fonte), LINK tenta corresponder ao nome. Se ele não é possível localizar uma correspondência exclusiva, o LINK emite uma mensagem de erro. Use o [DUMPBIN](../../build/reference/dumpbin-reference.md) ferramenta para obter o [nomes decorados](../../build/reference/decorated-names.md) formulário de um identificador quando você precisa especificá-lo para o vinculador.  
  
> [!NOTE]
>  Não especifique o formulário decorado de identificadores de C que são declarados `__cdecl` ou `__stdcall`.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)