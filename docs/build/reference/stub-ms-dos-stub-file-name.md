---
title: -STUB (nome de arquivo Stub MS-DOS) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /stub
- VC.Project.VCLinkerTool.DosStub
dev_langs: C++
helpviewer_keywords:
- Win32 [C++], attaching MS-DOS stub program
- STUB linker option
- MS-DOS stub file name linker option
- /STUB linker option
- Windows API [C++], attaching MS-DOS stub program
- -STUB linker option
ms.assetid: 65221ffe-4f9a-4a14-ac69-3cfb79b40b5f
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2bb7d1b9f56e7cea5d476d5ece6bdfab50fbe7a9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="stub-ms-dos-stub-file-name"></a>/STUB (nome de arquivo stub do MS-DOS)
```  
/STUB:filename  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *filename*  
 Um aplicativo do MS-DOS.  
  
## <a name="remarks"></a>Comentários  
 A opção /STUB anexa um programa stub MS-DOS a um programa Win32.  
  
 Um programa de stub é invocado se o arquivo for executado no MS-DOS. Ele geralmente exibe uma mensagem apropriada; No entanto, qualquer aplicativo MS-DOS válido pode ser um programa de stub.  
  
 Especifique um *filename* para o programa de stub após dois-pontos (:) na linha de comando. As verificações de vinculador *filename* e emite uma mensagem de erro se o arquivo não é um executável. O programa deve ser um arquivo .exe; um arquivo. com é inválido para um programa de stub.  
  
 Se essa opção não for usada, o vinculador anexa um programa de stub padrão que emite a seguinte mensagem:  
  
```  
This program cannot be run in MS-DOS mode.  
```  
  
 Ao compilar um driver de dispositivo virtual, *filename* permite que o usuário especifique um nome de arquivo que contém uma estrutura IMAGE_DOS_HEADER (definida em WINNT. H) a ser usado no VXD, em vez do cabeçalho padrão.  
  
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