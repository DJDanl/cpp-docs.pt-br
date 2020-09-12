---
title: Arquivos de recurso de projeto (C++)
ms.date: 05/14/2019
helpviewer_keywords:
- resource files
- resources [C++]
ms.assetid: 338a4a0f-0c62-4ef1-a34f-5d86262d93a4
ms.openlocfilehash: d37c3602d8939db609fc8af42dd764655195b24b
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041010"
---
# <a name="project-resource-files-c"></a>Arquivos de recurso de projeto (C++)

Recursos são elementos de interface que fornecem informações para o usuário. Bitmaps, ícones, barras de ferramentas e cursores são todos recursos. Alguns recursos podem executar uma ação, como selecionar uma opção em um menu ou inserir dados em uma caixa de diálogo.

Para saber mais, confira [Como trabalhar com recursos](../../windows/working-with-resource-files.md).

|Nome do arquivo|Local do diretório|Local do Gerenciador de Soluções|Descrição|
|---------------|------------------------|--------------------------------|-----------------|
|*Nome_do_projeto*.rc|*Project*|Arquivos de fonte|O arquivo de script de recurso do projeto. O arquivo de script de recurso contém o seguinte, dependendo do tipo de projeto e do suporte selecionado para o projeto (por exemplo, barras de ferramentas, caixas de diálogo ou HTML):<br /><br />- Definição de menu padrão.<br />- Tabelas de aceleradores e de cadeias de caracteres.<br />-A caixa **de diálogo padrão** .<br />- Outras caixas de diálogo.<br />-Arquivo de ícone (res \\ *proj*. ico).<br />- Informações de versão.<br />- Bitmaps.<br />- Barra de ferramentas.<br />- Arquivos HTML.<br /><br /> O arquivo de recurso inclui o arquivo Afxres.rc para os recursos padrão da Microsoft Foundation Class.|
|Resource.h|*Project*|Arquivos de cabeçalho|O arquivo de cabeçalho de recurso que inclui as definições para os recursos usados pelo projeto.|
|*Nome_do_projeto*.rc2|*Nome_do_projeto*\res|Arquivos de fonte|O arquivo de script que contém recursos adicionais usados pelo projeto. É possível incluir o arquivo .rc2 na parte superior do arquivo .rc do projeto.<br /><br /> Um arquivo .rc2 é útil para a inclusão dos recursos usados por vários projetos diferentes. Em vez de criar os mesmos recursos várias vezes para projetos diferentes, você pode colocá-los em um arquivo .rc2 e incluir o arquivo .rc2 no arquivo .rc principal.|
|*Nome_do_projeto*.def|*Project*|Arquivos de fonte|O arquivo de definição de módulo para um projeto de DLL. Para um controle, ele fornece o nome e a descrição do controle, bem como o tamanho do heap de tempo de execução.|
|*Nome_do_projeto*.ico|*Nome_do_projeto*\res|Arquivos de recursos|O arquivo de ícone para o projeto ou o controle. Esse ícone é exibido quando o aplicativo é minimizado. Ele também é usado na caixa **Sobre** do aplicativo. Por padrão, o MFC fornece o ícone do MFC e a ATL fornece o ícone da ATL.|
|*Nome_do_projeto*Doc.ico|*Nome_do_projeto*\res|Arquivos de recursos|O arquivo de ícone para um projeto MFC que inclui o suporte para a arquitetura de documento/exibição.|
|Toolbar.bmp|*Nome_do_projeto*\res|Arquivos de recursos|O arquivo de bitmap que representa o aplicativo ou o controle em uma barra de ferramentas ou uma paleta. Esse bitmap está incluído no arquivo de recurso do projeto. A barra de ferramentas inicial e a barra de status são construídas na classe **CMainFrame**.|
|ribbon.mfcribbon-ms|*Nome_do_projeto*\res|Arquivos de recursos|O arquivo de recurso que contém o código XML que define os botões, os controles e os atributos da faixa de opções. Para obter mais informações, confira [Designer da Faixa de Opções (MFC)](../../mfc/ribbon-designer-mfc.md).|

## <a name="see-also"></a>Confira também

[Tipos de arquivo criados para projetos do Visual Studio C++](file-types-created-for-visual-cpp-projects.md)
