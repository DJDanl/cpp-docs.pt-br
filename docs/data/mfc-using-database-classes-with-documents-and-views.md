---
title: 'MFC: Usando Classes de banco de dados com documentos e exibições | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- documents [C++], database applications
- recordsets [C++], documents and views
- CRecordView class, using in database forms
- views [C++], database applications
- forms [C++], database applications
- record views [C++], form-based applications
- document/view architecture [C++], in databases
- database applications [C++], forms
- database classes [C++], MFC
- ODBC recordsets [C++], documents and views
- ODBC [C++], forms
ms.assetid: 83979974-fc63-46ac-b162-e8403a572e2c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: fcaee376b53c1d592f02aafc830a35d72f64feeb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33091862"
---
# <a name="mfc-using-database-classes-with-documents-and-views"></a>MFC: usando classes de banco de dados com documentos e exibições
Você pode usar as classes de banco de dados MFC com ou sem a arquitetura de documento/exibição. Este tópico enfatiza a trabalhar com documentos e exibições. Ele explica:  
  
-   [Como escrever um aplicativo baseado em formulário](#_core_writing_a_form.2d.based_application) usando um `CRecordView` objeto como o modo de exibição principal no documento.  
  
-   [Como usar objetos de conjunto de registros em documentos e exibições](#_core_using_recordsets_in_documents_and_views).  
  
-   [Outras considerações](#_core_other_factors).  
  
 Para alternativas, consulte [MFC: usando Classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md).  
  
##  <a name="_core_writing_a_form.2d.based_application"></a> Escrevendo um aplicativo baseado em formulário  
 Muitos aplicativos de acesso a dados são baseados em formulários. A interface do usuário é um formulário que contém os controles no qual o usuário examina, insere ou edita dados. Para tornar o formulário de aplicativo com base, use a classe `CRecordView`. Quando você executar o Assistente de aplicativo MFC e selecione **ODBC** tipo de cliente no **suporte do banco de dados** página, o projeto usa `CRecordView` para a classe de exibição.
  
 Em um aplicativo baseado em formulário, cada objeto de exibição de registro armazena um ponteiro para um `CRecordset` objeto. Mecanismo de troca (RFX) de campos de registro do framework troca dados entre o conjunto de registros e a fonte de dados. Os dados de caixa de diálogo (DDX) mecanismo troca dados entre os membros de dados de campo do objeto recordset e os controles no formulário do exchange. `CRecordView` também fornece padrão funções de manipulador de comando para navegar de um registro para o registro no formulário.  
  
 Para criar um aplicativo baseado em formulário com o Assistente de aplicativo, consulte [criando um aplicativo do MFC com base em formulários](../mfc/reference/creating-a-forms-based-mfc-application.md) e [suporte de banco de dados, o Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md).  
  
 Para obter uma discussão completa sobre formulários, consulte [exibições de registro](../data/record-views-mfc-data-access.md).  
  
##  <a name="_core_using_recordsets_in_documents_and_views"></a> Usando conjuntos de registros em documentos e exibições  
 Muitos aplicativos baseados em formulário simples não é necessário para documentos. Se seu aplicativo é mais complexo, você provavelmente desejará usar um documento como um proxy para o banco de dados, armazenando uma `CDatabase` objeto que se conecta à fonte de dados. Aplicativos baseados em formulário geralmente armazenam um ponteiro para um objeto de conjunto de registros no modo de exibição. Outros tipos de aplicativos de banco de dados armazenam conjuntos de registros e `CDatabase` objeto do documento. Aqui estão algumas possibilidades de usar documentos em aplicativos de banco de dados:  
  
-   Se você estiver acessando um conjunto de registros em um contexto local, crie um `CRecordset` objeto localmente nas funções de membro do documento ou o modo de exibição, conforme necessário.  
  
     Declare um objeto recordset como uma variável local em uma função. Passar **nulo** para o construtor, que faz com que a estrutura criar e abrir um temporário `CDatabase` objeto para você. Como alternativa, passe um ponteiro para um `CDatabase` objeto. Use o conjunto de registros dentro da função e deixe-a ser destruída automaticamente quando a função for encerrada.  
  
     Quando você passa **nulo** para um construtor de conjunto de registros, a estrutura usa informações retornadas pelo conjunto de registros `GetDefaultConnect` a função de membro para criar um `CDatabase` de objeto e abri-lo. Os assistentes implementam `GetDefaultConnect` para você.  
  
-   Se você estiver acessando um conjunto de registros durante o tempo de vida do documento, insira um ou mais `CRecordset` objetos no documento.  
  
     Construa os objetos de conjunto de registros ao inicializar o documento ou conforme necessário. Você pode escrever uma função que retorna um ponteiro para o conjunto de registros se ele já existe ou cria e abre o conjunto de registros se ele ainda não existir. Fechar, excluir e recriar o conjunto de registros, conforme o necessário ou chamar seu **Requery** função de membro para atualizar os registros.  
  
-   Se você estiver acessando uma fonte de dados durante o tempo de vida do documento, incorpore um `CDatabase` de objeto ou armazenar um ponteiro para um `CDatabase` objeto nele.  
  
     O `CDatabase` objeto gerencia uma conexão à fonte de dados. O objeto é criado automaticamente durante a construção de documento e chamar sua **abrir** função de membro ao inicializar o documento. Quando você construir objetos de conjunto de registros em funções de membro de documento, você transmitir um ponteiro para o documento `CDatabase` objeto. Isso associa cada conjunto de registros com sua fonte de dados. O objeto de banco de dados geralmente é destruído quando o documento é fechado. Os objetos de conjunto de registros normalmente são destruídos quando sair do escopo de uma função.  
  
##  <a name="_core_other_factors"></a> Outros fatores  
 Aplicativos baseados em formulário geralmente não têm nenhum uso para o mecanismo de serialização do documento da estrutura, para que você talvez queira remover, desabilitar ou substituir o `New` e **abrir** comandos no **arquivo**menu. Consulte o artigo [serialização: vs de serialização. Banco de dados de entrada/saída](../mfc/serialization-serialization-vs-database-input-output.md).  
  
 Você também poderá fazer uso de muitas possibilidades de interface do usuário que a estrutura pode dar suporte. Por exemplo, você pode usar vários `CRecordView` objetos em uma janela separadora, abrir vários conjuntos de registros em diferentes várias janelas de documento com filho MDI (interface) e assim por diante.  
  
 Talvez você queira implementar a impressão de que estiver no modo de exibição, se ele é um formulário é implementado com `CRecordView` ou algo mais. Como as classes derivadas de `CFormView`, `CRecordView` não dá suporte a impressão, mas você pode substituir o `OnPrint` a função de membro para permitir a impressão. Para obter mais informações, consulte a classe [CFormView](../mfc/reference/cformview-class.md).  
  
 Não convém usar documentos e exibições. Nesse caso, consulte [MFC: usando Classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classes de banco de dados MFC (... / data/mfc-database-classes-odbc-and-dao.md)