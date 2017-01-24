---
title: "Cont&#234;ineres de controle ActiveX: programando controles ActiveX em um cont&#234;iner de controle ActiveX | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Contêineres de controle ActiveX [C++], acessando controles ActiveX"
  - "Contêineres de controle ActiveX [C++], classes wrapper"
  - "Controles ActiveX [C++], acessando"
  - "Controles ActiveX [C++], classes wrapper"
  - "Caixa de diálogo Confirmar Classes"
  - "arquivos de cabeçalho [C++], para classe wrapper de controle ActiveX"
  - "Controles ActiveX MFC [C++], acessando em contêineres"
  - "Classes wrapper [C++], Controles ActiveX"
  - "Classes wrapper [C++], usando"
ms.assetid: ef9b2480-92d6-4191-b16e-8055c4fd7b73
caps.latest.revision: 8
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres de controle ActiveX: programando controles ActiveX em um cont&#234;iner de controle ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve o processo para acessar [métodos](../mfc/mfc-activex-controls-methods.md) expostas e [propriedades](../mfc/mfc-activex-controls-properties.md) de controles ActiveX inseridos.  Basicamente, você seguirá estas etapas:  
  
1.  [Inserir um controle ActiveX no projeto do contêiner ActiveX](../mfc/inserting-a-control-into-a-control-container-application.md) usando a galeria do.  
  
2.  [Definir uma variável de membro](../mfc/activex-control-containers-connecting-an-activex-control-to-a-member-variable.md) \(ou outro formulário de acesso\) do mesmo tipo que a classe de invólucro do controle ActiveX.  
  
3.  [Programe o controle ActiveX](#_core_programming_the_activex_control) usando as funções de membro predefinidas da classe de invólucro.  
  
 Para esta discussão, suponhamos que você criou um projeto baseado diálogo\- \(Contêiner denominado\) com suporte do controle ActiveX.  O controle de exemplo de Circ, Circ, será adicionado ao projeto resultante.  
  
 Uma vez que o controle de Circ é inserido no projeto \(etapa 1\), insira uma instância do controle de Circ na caixa de diálogo principal do aplicativo.  
  
## Procedimentos  
  
#### Para adicionar o controle de Circ ao modelo da caixa de diálogo  
  
1.  Carregar o projeto do contêiner do controle ActiveX.  Para esse exemplo, use o projeto de `Container` .  
  
2.  Clique na guia da exibição de recursos.  
  
3.  Abra a pasta de **Caixa de Diálogo** .  
  
4.  Clique duas vezes no modelo principal da caixa de diálogo.  Para esse exemplo, use **IDD\_CONTAINER\_DIALOG**.  
  
5.  Clique no ícone de controle de Circ na caixa de ferramentas.  
  
6.  Clique em um ponto dentro da caixa de diálogo para inserir o controle de Circ.  
  
7.  No menu de **Arquivo** , escolha **Salvar Tudo** para salvar todas as alterações no modelo da caixa de diálogo.  
  
## Alterações no projeto  
 Para habilitar o aplicativo de contêiner acessar o controle de Circ, Visual C\+\+ adiciona automaticamente o arquivo de implementação da classe de invólucro \(`CCirc`\) \(.CPP\) ao projeto do contêiner e ao cabeçalho da classe de invólucro \(. H\) arquivo para o arquivo de cabeçalho da caixa de diálogo:  
  
 [!code-cpp[NVC_MFC_AxCont#1](../mfc/codesnippet/CPP/programming-activex-controls-in-a-activex-control-container_1.h)]  
  
##  <a name="_core_the_wrapper_class_header_28h29_file"></a> O cabeçalho da classe de invólucro \(. H\) Arquivo  
 Para obter e definir propriedades para invocar métodos \(e\) para o controle de Circ, a classe de invólucro de `CCirc` fornece uma declaração de todos os métodos e propriedades expostas.  No exemplo, essas instruções são encontradas em. CIRC.H.  O exemplo a seguir é a parte da classe `CCirc` que define as interfaces expostas do controle ActiveX:  
  
 [!code-cpp[NVC_MFC_AxCont#2](../mfc/codesnippet/CPP/programming-activex-controls-in-a-activex-control-container_2.h)]  
[!code-cpp[NVC_MFC_AxCont#3](../mfc/codesnippet/CPP/programming-activex-controls-in-a-activex-control-container_3.h)]  
  
 Essas funções podem ser chamadas de procedimentos de outro aplicativo usando a sintaxe normal C\+\+.  Para obter mais informações sobre como usar essa função de membro definida para acessar os métodos e as propriedades de controle, consulte a seção [Programando o controle ActiveX](#_core_programming_the_activex_control).  
  
##  <a name="_core_member_variable_modifications_to_the_project"></a> Alterações variáveis de membro ao projeto  
 Uma vez que o controle ActiveX foi adicionado ao projeto e inserido em um contêiner da caixa de diálogo, pode ser acessado por outras partes do projeto.  A maneira mais fácil de acessar o controle é a [crie uma variável de membro](../mfc/activex-control-containers-connecting-an-activex-control-to-a-member-variable.md) da classe da caixa de diálogo, `CContainerDlg` \(etapa 2\), que é do mesmo tipo que a classe de invólucro adicionada ao projeto pelo Visual C\+\+.  Você pode usar a variável de membro para acessar a qualquer momento o controle inserido.  
  
 Quando a caixa de diálogo de **Adicionar Variável de Membro** adiciona a variável de membro de `m_circctl` ao projeto, também adiciona as seguintes linhas no arquivo de cabeçalho \(. H\) da classe de `CContainerDlg` :  
  
 [!code-cpp[NVC_MFC_AxCont#4](../mfc/codesnippet/CPP/programming-activex-controls-in-a-activex-control-container_4.h)]  
[!code-cpp[NVC_MFC_AxCont#5](../mfc/codesnippet/CPP/programming-activex-controls-in-a-activex-control-container_5.h)]  
  
 Além disso, uma chamada a **DDX\_Control** é adicionado automaticamente à implementação de `CContainerDlg` de `DoDataExchange`:  
  
 [!code-cpp[NVC_MFC_AxCont#6](../mfc/codesnippet/CPP/programming-activex-controls-in-a-activex-control-container_6.cpp)]  
  
##  <a name="_core_programming_the_activex_control"></a> Programando o controle ActiveX  
 Neste momento, você insere o controle ActiveX no modelo da caixa de diálogo e criar uma variável de membro para ele.  Agora você pode usar a sintaxe comum do C\+\+ para acessar as propriedades e os métodos de controle inserido.  
  
 Como indicado em [O cabeçalho da classe de invólucro \(. H\) Arquivo](#_core_the_wrapper_class_header_28h29_file)\(\), o arquivo de cabeçalho \(. H\) para a classe de invólucro de `CCirc` , nesse caso, CIRC.H contém uma lista de funções de membro que podem ser usadas para obter e definir qualquer valor da propriedade exposto.  As funções de membro para métodos expostos também estão disponíveis.  
  
 Um local comum para alterar as propriedades do controle está na função de membro de `OnInitDialog` da classe principal da caixa de diálogo.  Essa função é chamada imediatamente antes da caixa de diálogo é exibida e é usada para inicializar o seu conteúdo, incluindo alguns de seus controles.  
  
 O exemplo de código usa a variável de membro de `m_circctl` para alterar as propriedades da legenda e de CircleShape de controle inserido de Circ:  
  
 [!code-cpp[NVC_MFC_AxCont#7](../mfc/codesnippet/CPP/programming-activex-controls-in-a-activex-control-container_7.cpp)]  
  
## Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)