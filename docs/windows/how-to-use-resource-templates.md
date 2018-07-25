---
title: 'Como: usar modelos de recurso | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- language-specific template files
- resource templates
- resources [Visual Studio], creating
- rct files
- templates, resource templates
- resources [Visual Studio], templates
- .rct files
ms.assetid: bdfe7060-f98e-4859-8285-9c8570360e9d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 534a86d10a4bcbc34e6cef29fbb77d7caa2c64b9
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33882726"
---
# <a name="how-to-use-resource-templates"></a>Como usar modelos de recurso
Um modelo de recurso é um recurso personalizado que você salvou como um arquivo. rct. Um modelo de recursos, em seguida, pode servir como um ponto de partida para a criação de outros recursos. Modelos de recursos economizar tempo no desenvolvimento de recursos adicionais ou grupos de recursos que compartilham recursos, como controles padrão e outros elementos repetidos. Por exemplo, você talvez queira incluir um botão de Ajuda e o ícone de um logotipo da empresa em várias caixas de diálogo. Para fazer tão rapidamente, crie um novo modelo de caixa de diálogo e personalizá-lo com o logotipo e o botão Ajuda.  
  
 Quando você tiver personalizado o modelo de recursos, você deve salvar as alterações na pasta de modelo (ou em qualquer local especificado no caminho de inclusão) para que apareça em seu tipo de recurso no novo modelo de recurso de [caixa de diálogo Adicionar recurso](../windows/add-resource-dialog-box.md). Você pode usar o novo modelo de recurso com a frequência conforme necessário.  
  
> [!NOTE]
>  Você pode colocar arquivos de modelo de idioma específico em subdiretórios do diretório do modelo principal. Por exemplo, você pode colocar arquivos de modelo apenas em inglês no \\< diretório de modelo de recurso\>\1033.  
  
### <a name="to-create-a-template-for-resources"></a>Para criar um modelo para recursos  
  
1.  Em **Solution Explorer**, clique com o botão direito.  
  
2.  No menu de atalho, escolha **adicionar**, em seguida, clique em **Adicionar Novo Item**.  
  
3.  No **Adicionar Novo Item** na caixa de **modelos:** painel, escolha **o arquivo de modelo de recursos (. rct)**.  
  
4.  Forneça um nome e local para o novo arquivo. rct e clique em **abrir**.  
  
5.  O novo arquivo. rct é adicionado ao seu projeto e aparece no Gerenciador de soluções sob o **recursos** pasta.  
  
     Você pode agora duas vezes no arquivo. rct para abri-lo em uma janela de documento e adicionar recursos a ele (clique no arquivo na janela do documento e escolha **adicionar recurso** no menu de atalho). Você pode personalizar esses recursos e salve o arquivo. rct.  
  
    > [!NOTE]
    >  Quando você cria um novo arquivo RCT, o Visual Studio pesquisa por ele no \Program Files\Microsoft Visual Studio 9.0\VC\VCResourceTemplates, no \Program Files\Microsoft Visual Studio 9.0\VC\VCResourceTemplates\\*LCID* ( como 1033 para inglês), *ou* em qualquer lugar do [caminho de inclusão](../windows/how-to-specify-include-directories-for-resources.md). Se você preferir armazenar seus arquivos RCT em outra pasta de arquivos, por exemplo \My documentos, basta adicionar essa pasta ao caminho de inclusão e Visual Studio encontrará seu arquivo RCT.  
  
### <a name="to-convert-an-existing-rc-file-to-an-rct-file"></a>Para converter um arquivo. rc existente em um arquivo. rct  
  
1.  [Abra o arquivo. rc como um arquivo autônomo](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).  
  
2.  Sobre o **arquivo** menu, clique em **salvar \< *seu nome de arquivo*> como**.  
  
3.  Especifique um local e clique em **Okey**.  
  
### <a name="to-create-a-new-resource-from-a-template"></a>Para criar um novo recurso de um modelo  
  
1.  No [exibição recursos](../windows/resource-view-window.md) painel, clique com botão direito no arquivo. RC e escolha **adicionar recurso** no menu de atalho.  
  
2.  No **adicionar recurso** caixa de diálogo, clique no sinal de adição (**+**) ao lado de um recurso para expandir o nó de recurso e ver todos os modelos disponíveis para esse recurso.  
  
3.  Clique duas vezes o modelo que você deseja usar.  
  
4.  Modificar o recurso adicional conforme necessário em seu editor de recursos.  
  
     O editor de recursos fornece automaticamente uma ID de recurso exclusivo. Você pode revisar o [propriedades do recurso](../windows/changing-the-properties-of-a-resource.md) conforme necessário.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.*  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)