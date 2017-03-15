---
title: "MFC: usando classes de banco de dados com documentos e exibi&#231;&#245;es | Microsoft Docs"
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
  - "Classe CDaoRecordView, usando em aplicativos de banco de dados"
  - "Classe CDaoRecordView, usando em formulários de banco de dados"
  - "Classe CRecordView, usando em formulários de banco de dados"
  - "DAO [C++], formulários em aplicativos de banco de dados"
  - "Conjuntos de registros DAO [C++]"
  - "Conjuntos de registros DAO [C++], documentos e exibições"
  - "aplicativos de banco de dados [C++], formulários"
  - "classes de banco de dados [C++], MFC"
  - "arquitetura de documento/exibição [C++], em bancos de dados"
  - "documentos [C++], aplicativos de banco de dados"
  - "formulários [C++], aplicativos de banco de dados"
  - "ODBC [C++], formulários"
  - "conjuntos de registros ODBC [C++], documentos e exibições"
  - "exibições de registro [C++], aplicativos baseados em formulário"
  - "conjunto de registros [C++], documentos e exibições"
  - "exibições [C++], aplicativos de banco de dados"
ms.assetid: 83979974-fc63-46ac-b162-e8403a572e2c
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# MFC: usando classes de banco de dados com documentos e exibi&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar as classes da base de dados de MFC — DAO ou ODBC — com ou sem a arquitetura do documento\/exibição.  Este tópico enfatiza trabalhar com documentos e exibições.  Explica:  
  
-   [Como escrever um aplicativo de autenticação baseado](#_core_writing_a_form.2d.based_application) usando um objeto de `CRecordView` ou de `CDaoRecordView` como a exibição principal no documento.  
  
-   [Como usar objetos do conjunto de registros em seus documentos e exibições](#_core_using_recordsets_in_documents_and_views).  
  
-   [Outras considerações](#_core_other_factors).  
  
 Para [MFC: Usar a base de dados de classificação sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md)de backup, consulte.  
  
##  <a name="_core_writing_a_form.2d.based_application"></a> Escrevendo um aplicativo de autenticação baseado  
 Muitos aplicativos de acesso a dados se baseiam em formulários.  A interface do usuário é um formulário que contém os controles para o qual o usuário examina, inserir, ou edita dados.  Para fazer seu formulário de candidatura baseado, use a classe `CRecordView` ou `CDaoRecordView`.  Quando você executa o assistente de aplicativo MFC e selecione o tipo de cliente de **ODBC** na página de **Database Support** , o projeto usará `CRecordView` da classe de exibição.  Os assistentes não oferecem suporte a DAO portanto, se você quiser usar `CDaoRecordView`, você tem que codificar\-lo manualmente.  
  
 Em um aplicativo de autenticação baseado, cada objeto de exibição do registro armazena um ponteiro para um objeto de `CRecordset` ou de `CDaoRecordset` .  Troca dados do mecanismo de troca do campo de registro de estrutura \(RFX\) entre o conjunto de registros e a fonte de dados.  Troca dados de troca de dados do mecanismo da caixa de diálogo \(DDX\) entre os membros de dados do campo do objeto do conjunto de registros e os controles no formulário.  `CRecordView` ou `CDaoRecordView` também fornecem funções padrão de manipulador de comando para navegar do registro ao registro no formulário.  
  
 Para criar um aplicativo de autenticação baseado com o assistente de aplicativo, consulte [Criando um aplicativo de autenticação baseado MFC](../Topic/Creating%20a%20Forms-Based%20MFC%20Application.md) e [Suporte de base de dados do aplicativo, o assistente MFC](../mfc/reference/database-support-mfc-application-wizard.md).  
  
 Para uma discussão completa de formulários, consulte [Registrar exibições](../data/record-views-mfc-data-access.md).  
  
##  <a name="_core_using_recordsets_in_documents_and_views"></a> Usando conjuntos de registros em documentos e exibições  
 Muitos aplicativos com base em formulários simples não precisam de documentos.  Se seu aplicativo for mais complexo, você deseja que provavelmente para usar um documento como um proxy para o base de dados, armazenando um objeto de `CDatabase` ou de `CDaoDatabase` que se conecta à fonte de dados.  Os aplicativos com base em formulários armazenam geralmente um ponteiro para um objeto do conjunto de registros na exibição.  Outros tipos de aplicativos de base de dados armazenam conjuntos de registros e `CDatabase` ou objeto de `CDaoDatabase` no documento.  Aqui estão algumas possibilidades para usar documentos em aplicativos de base de dados:  
  
-   Se você estiver acessando um conjunto de registros em um contexto local, crie um objeto de `CRecordset` ou de `CDaoRecordset` localmente em funções de membro do documento ou exibição, quando necessário.  
  
     Declare um objeto do conjunto de registros como uma variável local em uma função.  Passe **nulo** ao construtor, que faz com que a estrutura criar e abrir `CDatabase` ou um objeto temporário de `CDaoDatabase` para você.  Como alternativa, transmitir um ponteiro para um objeto de `CDatabase` ou de `CDaoDatabase` .  Use o conjunto de registros dentro da função e deixe\-o ser destruído automaticamente quando a função é encerrado.  
  
     Quando você passa **nulo** a um construtor do conjunto de registros, a estrutura usa as informações retornadas pela função de membro de `GetDefaultConnect` do conjunto de registros para criar um objeto de `CDatabase` ou de `CDaoDatabase` e para abri\-lo.  Os assistentes implementam `GetDefaultConnect` para você.  
  
-   Se você estiver acessando um conjunto de registros durante o tempo de vida do documento, inserir um ou mais objetos de `CRecordset` ou de `CDaoRecordset` no documento.  
  
     Construir os objetos do conjunto de registros enquanto você inicialize o documento ou quando necessário.  Você pode escrever uma função que retorna um ponteiro para o conjunto de registros se já exista ou esteja aberta e constrói o conjunto de registros caso ainda não exista.  Fechar, excluir e recriar o conjunto de registros quando necessário, ou chame a função de membro de **Requery** para atualizar registros.  
  
-   Se você estiver acessando uma fonte de dados durante o tempo de vida do documento, incorpore um objeto de `CDatabase` ou de `CDaoDatabase` ou armazenar um ponteiro para um objeto de `CDatabase` ou de `CDaoDatabase` nele.  
  
     O objeto de `CDatabase` ou de `CDaoDatabase` gerencia uma conexão à fonte de dados.  O objeto é criado automaticamente durante a compilação do documento, e você chama a função de membro de **Abrir** ao inicializar o documento.  Quando você cria objetos do conjunto de registros em funções de membro do documento, você passa um ponteiro para o objeto de `CDatabase` ou de `CDaoDatabase` do documento.  Isso vincula cada conjunto de registros com a sua fonte de dados.  O objeto de base de dados é destruído normalmente quando o documento é encerrada.  Os objetos do conjunto de registros são destruídos normalmente quando saem do escopo de uma função.  
  
##  <a name="_core_other_factors"></a> Outros fatores  
 Os aplicativos com base em formulários geralmente não têm nenhum uso do mecanismo de serialização do documento da estrutura, de modo que talvez você queira remover, desabilite, ou substituir os comandos de `New` e de **Abrir** no menu de **Arquivo** .  Consulte o artigo [Serialização: Serialização na base de dados de entrada](../mfc/serialization-serialization-vs-database-input-output.md).  
  
 Talvez você também queira utilizar várias possibilidades da interface do usuário que a estrutura pode dar suporte.  Por exemplo, você pode usar vários `CRecordView` ou os objetos em uma janela do divisor, vários conjuntos de registros de `CDaoRecordView` abertos nas janelas filho diferentes de \(MDI\) interface de documentos, e assim por diante.  
  
 Talvez você queira implementar a impressão de que existir em sua exibição, se é um formulário implementado com `CRecordView` ou `CDaoRecordView` ou algo mais.  Como as classes derivadas de `CFormView`, `CRecordView` e `CDaoRecordView` não dão suporte a impressão, mas você pode substituir a função de membro de `OnPrint` para permitir imprimir.  Classe de [CFormView](../mfc/reference/cformview-class.md)Para obter mais informações, consulte.  
  
 Você não pode usar documentos e exibições de todos eles.  Nesse caso, consulte [MFC: Usar a base de dados de classificação sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md).  
  
## Consulte também  
 [Classes de banco de dados MFC \(ODBC e DAO\)](../Topic/MFC%20Database%20Classes%20\(ODBC%20and%20DAO\).md)