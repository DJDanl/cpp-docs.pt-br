---
title: "Páginas de propriedade do vinculador | Microsoft Docs"
ms.custom: 
ms.date: 11/21/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.RegisterOutput
- VC.Project.VCLinkerTool.OVERWRITEImportLibrary
- VC.Project.VCLinkerTool.UseLibraryDependencyInputs
- VC.Project.VCLinkerTool.LinkLibraryDependencies
dev_langs:
- C++
helpviewer_keywords:
- per-user redirection
- Linker property pages
ms.assetid: 7e7671e5-a35a-4e67-9bdb-661d75c4d11e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1b8a1d0d4775955ee55aa0f40ac10a75cda54379
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-property-pages"></a>Páginas de propriedade do vinculador

Este tópico discute as propriedades a seguir sobre o **geral** página de propriedade do vinculador. Para a versão do Linux dessa página, consulte [propriedades de vinculador (C++ Linux)](../linux/prop-pages/linker-linux.md).

## <a name="general-page-properties"></a>Propriedades da página geral

### <a name="ignore-import-library"></a>Ignorar biblioteca de importações

Esta propriedade instrui o vinculador para não vincular nenhuma saída. lib gerada a partir desta compilação em qualquer projeto dependente. Isso permite que o sistema de projeto lidar com arquivos. dll que não produzem um arquivo quando criada. Se um projeto depende de outro projeto que produz uma DLL, o sistema do projeto vincula automaticamente o arquivo. lib produzido pelo projeto filho. Isso pode não ser necessária por projetos que estão produzindo DLLs COM ou DLLs somente de recursos; essas DLLs não tem qualquer exportações significativas. Se uma DLL não exporta o vinculador não gera um arquivo. Se nenhum arquivo. lib de exportação está presente no disco, e o sistema de projeto informa o vinculador a vincular essa DLL (ausente), o link falhar. Use o **ignorar biblioteca de importações** propriedade para resolver esse problema. Quando definido como **Sim**, o sistema do projeto ignora a presença ou ausência do arquivo. lib e faz com que qualquer projeto que depende deste projeto não vincule com o arquivo. lib inexistente.

Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreImportLibrary%2A>.

### <a name="register-output"></a>Registrar saída

Executa `regsvr32.exe /s $(TargetPath)` na saída da compilação, que é válido apenas em projetos. dll. Para projetos de .exe, essa propriedade será ignorada. Para registrar uma saída de .exe, defina um evento postbuild na configuração de fazer o registro personalizado que é sempre necessário para arquivos .exe registrado.

Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.RegisterOutput%2A>.

### <a name="per-user-redirection"></a>Redirecionamento por usuário

Registro no Visual Studio tradicionalmente foi feito em HKEY_CLASSES_ROOT (HKCR). Com [!INCLUDE[wiprlhext](../c-runtime-library/reference/includes/wiprlhext_md.md)], para acessar HKCR deve executar o Visual Studio no modo elevado. Os desenvolvedores não desejar sempre executar no modo elevado, mas ainda devem trabalhar com o registro. Redirecionamento por usuário permite que você registre sem precisar executar nesse modo.

Redirecionamento de usuário individual forçará as gravações de qualquer para HKCR a serem redirecionadas para HKEY\_atual\_usuário (HKCU). Se o redirecionamento por usuário esteja desativado, isso poderá causar [prj0050 no projeto de compilação erro](../error-messages/tool-errors/project-build-error-prj0050.md) quando o programa tenta gravar HKCR.

### <a name="link-library-dependencies"></a>Dependências de biblioteca de link

Especifica se deve vincular os arquivos. lib que são produzidos por projetos dependentes. Normalmente, você deseja vincular nos arquivos. lib, mas isso não pode ser o caso para determinadas DLLs.

Você também pode especificar um arquivo. obj, fornecendo o nome de arquivo e o caminho relativo, por exemplo "... \\.. \MyLibProject\MyObjFile.obj". Se a fonte de código para o arquivo. obj #includes um cabeçalho pré-compilado, por exemplo pch. h, em seguida, o arquivo pch.obj está localizado na mesma pasta que MyObjFile.obj e você também deverá adicionar pch.obj como uma dependência adicional.

### <a name="use-library-dependency-inputs"></a>Usar entradas de dependência de biblioteca

Em um projeto grande, quando um projeto dependente produz um arquivo. lib, vínculo incremental está desabilitado. Se houver muitos projetos dependentes que produzem arquivos. lib, a criação do aplicativo pode levar muito tempo. Quando essa propriedade é definida como **Sim**, os links do sistema de projeto nos arquivos. obj para .libs produzido por projetos dependentes, permitindo vínculo incremental.

Para obter informações sobre como acessar o **geral** página de propriedade do vinculador, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).

## <a name="see-also"></a>Consulte também

[Caixa de diálogo Configurações do Projeto do VC++, Projetos e Soluções, Opções](/visualstudio/ide/reference/vcpp-project-settings-projects-and-solutions-options-dialog-box)  
[Páginas de propriedade](../ide/property-pages-visual-cpp.md)  