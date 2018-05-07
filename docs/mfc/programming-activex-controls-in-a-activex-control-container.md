---
title: 'Contêineres de controle ActiveX: Programando controles ActiveX em um contêiner de controle ActiveX | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bae926cfc7e83edeef9ee68c7ce7118c55009a08
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="activex-control-containers-programming-activex-controls-in-an-activex-control-container"></a>Contêineres de controle ActiveX: programando controles ActiveX em um contêiner de controle ActiveX
Este artigo descreve o processo para acessar o exposto [métodos](../mfc/mfc-activex-controls-methods.md) e [propriedades](../mfc/mfc-activex-controls-properties.md) de controles ActiveX incorporados. Basicamente, você seguirá estas etapas:  
  
1.  [Inserir um controle ActiveX para o projeto de contêiner ActiveX](../mfc/inserting-a-control-into-a-control-container-application.md) usando a Galeria.  
  
2.  [Definir uma variável de membro](../mfc/activex-control-containers-connecting-an-activex-control-to-a-member-variable.md) (ou outra forma de acesso) do mesmo tipo como o ActiveX controlar classe wrapper.  
  
3.  [O controle ActiveX de programa](#_core_programming_the_activex_control) usando funções de membro da classe wrapper predefinidas.  
  
 Para esta discussão, suponha que você criou um projeto baseado na caixa de diálogo (contêiner nomeado) com suporte a controles ActiveX. O controle de exemplo c, c, será adicionado ao projeto resultante.  
  
 Depois que o controle de c é inserido no projeto (etapa 1), insira uma instância do controle c na caixa de diálogo principal do aplicativo.  
  
## <a name="procedures"></a>Procedimentos  
  
#### <a name="to-add-the-circ-control-to-the-dialog-template"></a>Para adicionar o controle de c para o modelo de caixa de diálogo  
  
1.  Carregar o projeto de contêiner de controle ActiveX. Para este exemplo, use o `Container` projeto.  
  
2.  Clique na guia de exibição de recursos.  
  
3.  Abra o **diálogo** pasta.  
  
4.  Clique duas vezes o modelo de caixa de diálogo principal. Para este exemplo, use **IDD_CONTAINER_DIALOG**.  
  
5.  Clique no ícone de controle de c na caixa de ferramentas.  
  
6.  Clique em um ponto dentro da caixa de diálogo para inserir o controle de c.  
  
7.  Do **arquivo** menu, escolha **Salvar tudo** para salvar todas as modificações para o modelo de caixa de diálogo.  
  
## <a name="modifications-to-the-project"></a>Modificações ao projeto  
 Para habilitar o aplicativo de contêiner acessar o controle de c, o Visual C++ adiciona automaticamente a classe de invólucro (`CCirc`) o arquivo de implementação (. CPP) para o projeto do contêiner e o cabeçalho de classe wrapper (. H) o arquivo para o arquivo de cabeçalho da caixa de diálogo:  
  
 [!code-cpp[NVC_MFC_AxCont#1](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_1.h)]  
  
##  <a name="_core_the_wrapper_class_header_28h29_file"></a> O cabeçalho de classe Wrapper (. H) arquivo  
 Para obter e definir propriedades (e chamar métodos) para o controle de c, a `CCirc` classe wrapper fornece uma declaração de exposto todos os métodos e propriedades. No exemplo, essas declarações são encontradas em CIRC. H. O exemplo a seguir é a parte da classe `CCirc` que define as interfaces expostas do controle ActiveX:  
  
 [!code-cpp[NVC_MFC_AxCont#2](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_2.h)]  
[!code-cpp[NVC_MFC_AxCont#3](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_3.h)]  
  
 Essas funções, em seguida, podem ser chamadas de outros procedimentos do aplicativo usando a sintaxe de C++ normal. Para obter mais informações sobre como usar essa função de membro definida para acessar os métodos e propriedades do controle, consulte a seção [programar o controle ActiveX](#_core_programming_the_activex_control).  
  
##  <a name="_core_member_variable_modifications_to_the_project"></a> Modificações de variável de membro para o projeto  
 Depois que o controle ActiveX foi adicionado ao projeto e inserido em um contêiner de caixa de diálogo, ele pode ser acessado por outras partes do projeto. A maneira mais fácil para o controle de acesso é [criar uma variável de membro](../mfc/activex-control-containers-connecting-an-activex-control-to-a-member-variable.md) da classe de caixa de diálogo, `CContainerDlg` (etapa 2), que é do mesmo tipo de classe wrapper adicionado ao projeto pelo Visual C++. Você pode usar a variável de membro para acessar o controle incorporado a qualquer momento.  
  
 Quando o **Adicionar variável de membro** caixa de diálogo adiciona o `m_circctl` membro variável ao projeto, ele também adiciona as seguintes linhas no arquivo de cabeçalho (. H) do `CContainerDlg` classe:  
  
 [!code-cpp[NVC_MFC_AxCont#4](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_4.h)]  
[!code-cpp[NVC_MFC_AxCont#5](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_5.h)]  
  
 Além disso, uma chamada para **DDX_Control** é adicionado automaticamente para o `CContainerDlg`da implementação do `DoDataExchange`:  
  
 [!code-cpp[NVC_MFC_AxCont#6](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_6.cpp)]  
  
##  <a name="_core_programming_the_activex_control"></a> O controle ActiveX de programação  
 Neste ponto, você ter inserido o controle ActiveX em seu modelo de caixa de diálogo e criado uma variável de membro para ele. Agora você pode usar a sintaxe de C++ comum para acessar as propriedades e métodos do controle inserido.  
  
 Conforme observado (no [o cabeçalho de classe Wrapper (. Arquivo H)](#_core_the_wrapper_class_header_28h29_file)), o arquivo de cabeçalho (. H) para o `CCirc` classe wrapper neste caso CIRC. H, contém uma lista de funções de membro que você pode usar para obter e definir qualquer valor de propriedade exposta. Funções de membro para métodos expostos também estão disponíveis.  
  
 Um local comum para modificar as propriedades do controle está no `OnInitDialog` a função de membro da classe principal da caixa de diálogo. Essa função é chamada logo antes da caixa de diálogo aparece e é usada para inicializar o seu conteúdo, inclusive qualquer um de seus controles.  
  
 O seguinte exemplo de código usa o `m_circctl` variável de membro para modificar as propriedades da legenda e CircleShape do controle inserido c:  
  
 [!code-cpp[NVC_MFC_AxCont#7](../mfc/codesnippet/cpp/programming-activex-controls-in-a-activex-control-container_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

