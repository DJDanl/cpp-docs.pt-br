---
title: 'Contêineres de controle ActiveX: programando controles ActiveX em um contêiner de controle ActiveX'
ms.date: 09/12/2018
helpviewer_keywords:
- ActiveX control containers [MFC], accessing ActiveX controls
- Confirm Classes dialog box
- wrapper classes [MFC], ActiveX controls
- ActiveX control containers [MFC], wrapper classes
- ActiveX controls [MFC], accessing
- MFC ActiveX controls [MFC], accessing in containers
- header files [MFC], for ActiveX control wrapper class
- wrapper classes [MFC], using
- ActiveX controls [MFC], wrapper classes
ms.assetid: ef9b2480-92d6-4191-b16e-8055c4fd7b73
ms.openlocfilehash: 9620f4d47197147db4972c9f2024f6018a705902
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371183"
---
# <a name="activex-control-containers-programming-activex-controls-in-an-activex-control-container"></a>Contêineres de controle ActiveX: programando controles ActiveX em um contêiner de controle ActiveX

Este artigo descreve o processo de acesso aos métodos e [propriedades](../mfc/mfc-activex-controls-properties.md) [expostos](../mfc/mfc-activex-controls-methods.md) dos controles ActiveX incorporados.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

Basicamente, você seguirá estes passos:

1. [Insira um controle ActiveX no projeto de contêiner ActiveX](../mfc/inserting-a-control-into-a-control-container-application.md) usando a Galeria.

1. [Defina uma variável de membro](../mfc/activex-control-containers-connecting-an-activex-control-to-a-member-variable.md) (ou outra forma de acesso) do mesmo tipo que a classe de invólucro de controle ActiveX.

1. [Programe o controle ActiveX](#_core_programming_the_activex_control) usando funções de membro predefinidas da classe de invólucro.

Para essa discussão, suponha que você criou um projeto baseado em diálogo (chamado Container) com suporte ao controle ActiveX. O controle de amostras do Circ, Circ, será adicionado ao projeto resultante.

Uma vez que o controle Circ seja inserido no projeto (etapa 1), insira uma instância do controle Circ na caixa de diálogo principal do aplicativo.

## <a name="procedures"></a>Procedimentos

#### <a name="to-add-the-circ-control-to-the-dialog-template"></a>Para adicionar o controle Circ ao modelo de diálogo

1. Carregue o projeto do contêiner de controle ActiveX. Para este exemplo, `Container` use o projeto.

1. Clique na guia 'Exibir recursos'.

1. Abra a pasta **Diálogo.**

1. Clique duas vezes no modelo da caixa de diálogo principal. Para este exemplo, use **IDD_CONTAINER_DIALOG**.

1. Clique no ícone de controle Circ na caixa de ferramentas.

1. Clique em um ponto dentro da caixa de diálogo para inserir o controle Circ.

1. No menu **Arquivo,** escolha **Salvar tudo** para salvar todas as modificações no modelo da caixa de diálogo.

## <a name="modifications-to-the-project"></a>Modificações no Projeto

Para permitir que o aplicativo Container acesse o controle Circ, o`CCirc`Visual C++ adiciona automaticamente o arquivo de implementação da classe wrapper ( ) (. CPP) para o projeto Container e o cabeçalho da classe wrapper (. H) arquivo para o arquivo de cabeçalho da caixa de diálogo:

[!code-cpp[NVC_MFC_AxCont#1](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_1.h)]

## <a name="the-wrapper-class-header-h-file"></a><a name="_core_the_wrapper_class_header_28h29_file"></a>O Cabeçalho da Classe de Embalagem (. H) Arquivo

Para obter e definir propriedades (e invocar métodos) `CCirc` para o controle circ, a classe de invólucro fornece uma declaração de todos os métodos e propriedades expostos. No exemplo, essas declarações são encontradas no CIRC. H. A amostra a seguir `CCirc` é a parte da classe que define as interfaces expostas do controle ActiveX:

[!code-cpp[NVC_MFC_AxCont#2](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_2.h)]
[!code-cpp[NVC_MFC_AxCont#3](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_3.h)]

Essas funções podem então ser chamadas de outros procedimentos do aplicativo usando sintaxe C++. Para obter mais informações sobre o uso deste conjunto de funções de membro para acessar os métodos e propriedades do controle, consulte a seção [Programação do controle ActiveX](#_core_programming_the_activex_control).

## <a name="member-variable-modifications-to-the-project"></a><a name="_core_member_variable_modifications_to_the_project"></a>Modificações variáveis de membros para o projeto

Uma vez que o controle ActiveX tenha sido adicionado ao projeto e incorporado em um recipiente de caixa de diálogo, ele pode ser acessado por outras partes do projeto. A maneira mais fácil de acessar o controle é criar `CContainerDlg` uma variável [membro](../mfc/activex-control-containers-connecting-an-activex-control-to-a-member-variable.md) da classe de diálogo, (etapa 2), que é do mesmo tipo que a classe de invólucro adicionada ao projeto pelo Visual C++. Em seguida, você pode usar a variável membro para acessar o controle incorporado a qualquer momento.

Quando a caixa de diálogo **Adicionar variável de membro** adiciona a variável membro *m_circctl* ao projeto, ela também adiciona as seguintes linhas ao arquivo de cabeçalho (. H) da `CContainerDlg` classe:

[!code-cpp[NVC_MFC_AxCont#4](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_4.h)]
[!code-cpp[NVC_MFC_AxCont#5](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_5.h)]

Além disso, uma chamada para **DDX_Control** `CContainerDlg`é automaticamente `DoDataExchange`adicionada à implementação de :

[!code-cpp[NVC_MFC_AxCont#6](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_6.cpp)]

## <a name="programming-the-activex-control"></a><a name="_core_programming_the_activex_control"></a>Programação do Controle ActiveX

Neste ponto, você inseriu o controle ActiveX em seu modelo de diálogo e criou uma variável de membro para ele. Agora você pode usar a sintaxe C++ comum para acessar as propriedades e métodos do controle incorporado.

Como observado (em [The Wrapper Class Header (. H) Arquivo](#_core_the_wrapper_class_header_28h29_file)), o arquivo de cabeçalho (. H) para `CCirc` a classe de invólucro, neste caso CIRC. H, contém uma lista de funções de membro que você pode usar para obter e definir qualquer valor de propriedade exposto. As funções dos membros para métodos expostos também estão disponíveis.

Um lugar comum para modificar as `OnInitDialog` propriedades do controle está na função membro da classe de diálogo principal. Esta função é chamada pouco antes da caixa de diálogo aparecer e é usada para inicializar seu conteúdo, incluindo qualquer um de seus controles.

O exemplo de código a seguir usa a variável *membro m_circctl* para modificar as propriedades Caption e CircleShape do controle Circ incorporado:

[!code-cpp[NVC_MFC_AxCont#7](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_7.cpp)]

## <a name="see-also"></a>Confira também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)
