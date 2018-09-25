---
title: Páginas de propriedades do Vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/21/2017
ms.technology:
- cpp-ide
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eec1620d9ae84e5c0b957b7426ad388c70626813
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46379210"
---
# <a name="linker-property-pages"></a>Páginas de propriedade do vinculador

Este tópico aborda as propriedades a seguir na página de propriedades **Geral** do vinculador. Para obter a versão do Linux desta página, confira [Propriedades do vinculador (Linux C++)](../linux/prop-pages/linker-linux.md).

## <a name="general-page-properties"></a>Propriedades gerais da página

### <a name="ignore-import-library"></a>Ignorar Biblioteca de Importação

Essa propriedade instrui o vinculador a não vincular nenhuma saída .lib gerada por esse build a nenhum projeto dependente. Isso permite que o sistema de projeto manipule arquivos .dll que não produzem um arquivo .lib quando compilados. Se um projeto depende de outro projeto que produz uma DLL, o sistema do projeto vincula automaticamente o arquivo .lib produzido por esse projeto filho. Isso pode não ser necessário para projetos que produzem DLLs COM ou DLLs somente de recursos; essas DLLs não têm exportações significativas. Se uma DLL não tem exportações, o vinculador não gera um arquivo .lib. Se nenhum arquivo .lib de exportação estiver presente no disco e o sistema de projeto instruir o vinculador a ser vinculado a essa DLL (ausente), o vínculo falhará. Use a propriedade **Ignorar Biblioteca de Importação** para resolver esse problema. Quando definido como **Sim**, o sistema de projeto ignora a presença ou a ausência do arquivo .lib e faz com que qualquer projeto que dependa desse projeto não seja vinculado ao arquivo .lib inexistente.

Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreImportLibrary%2A>.

### <a name="register-output"></a>Registrar Saída

Executa `regsvr32.exe /s $(TargetPath)` na saída de build, que é válido somente em projetos .dll. Para projetos .exe, essa propriedade é ignorada. Para registrar uma saída .exe, defina um evento pós-build na configuração para fazer o registro personalizado que é sempre necessário para arquivos .exe registrados.

Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.RegisterOutput%2A>.

### <a name="per-user-redirection"></a>Redirecionamento por usuário

Tradicionalmente, o registro no Visual Studio é feito em HKEY_CLASSES_ROOT (HKCR). Com o Windows Vista e sistemas operacionais posteriores, para acessar HKCR, é necessário executar o Visual Studio no modo elevado. Os desenvolvedores nem sempre desejam executá-lo no modo elevado, mas ainda precisam trabalhar com o registro. O redirecionamento por usuário permite que você faça o registro sem precisar executar o Visual Studio nesse modo.

O redirecionamento por usuário força as gravações em HKCR a serem redirecionadas para HKEY\_CURRENT\_USER (HKCU). Se o redirecionamento por usuário estiver desativado, isso poderá causar o [Erro de Build PRJ0050 do Projeto](../error-messages/tool-errors/project-build-error-prj0050.md) quando o programa tentar fazer uma gravação em HKCR.

### <a name="link-library-dependencies"></a>Dependências da Biblioteca de Links

Especifica se os arquivos .lib produzidos por projetos dependentes devem ser vinculados. Normalmente, você deseja criar um vínculo com os arquivos .lib, mas esse pode não ser o caso para algumas DLLs.

Especifique também um arquivo .obj fornecendo o nome de arquivo e o caminho relativo, por exemplo, "..\\..\MyLibProject\MyObjFile.obj". Se o código-fonte do arquivo .obj incluir um cabeçalho pré-compilado, por exemplo pch.h, o arquivo pch.obj estará localizado na mesma pasta de MyObjFile.obj e você também precisará adicionar pch.obj como uma dependência adicional.

### <a name="use-library-dependency-inputs"></a>Usar Entradas de Dependência da Biblioteca

Em um projeto grande, quando um projeto dependente produz um arquivo .lib, o vínculo incremental é desabilitado. Se houver muitos projetos dependentes que produzem arquivos .lib, a compilação do aplicativo poderá levar muito tempo. Quando essa propriedade é definida como **Sim**, o sistema de projeto cria o vínculo nos arquivos .obj para os .libs produzidos por projetos dependentes, permitindo o vínculo incremental.

Para obter informações sobre como acessar a página de propriedades **Geral** do vinculador, confira [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).

## <a name="see-also"></a>Consulte também

[Caixa de diálogo Configurações do Projeto do VC++, Projetos e Soluções, Opções](/visualstudio/ide/reference/vcpp-project-settings-projects-and-solutions-options-dialog-box)<br>
[Páginas de propriedade](../ide/property-pages-visual-cpp.md)