---
title: 'MFC: Usando Classes de banco de dados com documentos e exibições'
ms.date: 11/04/2016
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
ms.openlocfilehash: 78765d17b52889123f13c492699230834decba66
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62182886"
---
# <a name="mfc-using-database-classes-with-documents-and-views"></a>MFC: Usando Classes de banco de dados com documentos e exibições

Você pode usar as classes de banco de dados do MFC com ou sem a arquitetura de documento/exibição. Este tópico enfatiza a trabalhar com documentos e exibições. Ele explica:

- [Como escrever um aplicativo baseado em formulário](#_core_writing_a_form.2d.based_application) usando um `CRecordView` objeto como o modo de exibição principal no seu documento.

- [Como usar objetos de conjunto de registros em seus documentos e exibições](#_core_using_recordsets_in_documents_and_views).

- [Outras considerações](#_core_other_factors).

Para alternativas, consulte [MFC: Usando Classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md).

##  <a name="_core_writing_a_form.2d.based_application"></a> Escrevendo um aplicativo baseado em formulário

Muitos aplicativos de acesso a dados são baseados em formulários. A interface do usuário é um formulário contendo controles em que o usuário examina, insere ou edita dados. Para tornar o formulário de aplicativo com base, use a classe `CRecordView`. Quando você executar o Assistente de aplicativo do MFC e seleciona **ODBC** tipo de cliente na **suporte do banco de dados** página, o projeto usa `CRecordView` para a classe de exibição.

Em um aplicativo baseado em formulário, cada objeto de exibição de registro armazena um ponteiro para um `CRecordset` objeto. Mecanismo de exchange (RFX) de campos de registro da estrutura troca dados entre o conjunto de registros e a fonte de dados. Os dados de caixa de diálogo (DDX) mecanismo troca dados entre os controles no formulário e os membros de dados do campo do objeto recordset do exchange. `CRecordView` também fornece padrão funções de manipulador de comando para navegar de um registro para o registro no formulário.

Para criar um aplicativo baseado em formulário com o Assistente de aplicativo, consulte [criando um aplicativo do MFC com base em formulários](../mfc/reference/creating-a-forms-based-mfc-application.md) e [suporte de banco de dados, o Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md).

Para obter uma discussão completa sobre formulários, consulte [exibições de registro](../data/record-views-mfc-data-access.md).

##  <a name="_core_using_recordsets_in_documents_and_views"></a> Usando conjuntos de registros em documentos e exibições

Muitos aplicativos simples baseados em formulário não é necessário para documentos. Se seu aplicativo é mais complexo, você provavelmente desejará usar um documento como um proxy para o banco de dados, armazenando um `CDatabase` objeto que se conecta à fonte de dados. Aplicativos baseados em formulário geralmente armazenam um ponteiro para um objeto de conjunto de registros no modo de exibição. Outros tipos de aplicativos de banco de dados armazenam conjuntos de registros e `CDatabase` objeto no documento. Aqui estão algumas possibilidades para usar documentos em aplicativos de banco de dados:

- Se você estiver acessando um conjunto de registros em um contexto local, crie um `CRecordset` objeto localmente nas funções de membro do documento ou o modo de exibição, conforme necessário.

   Declare um objeto de conjunto de registros como uma variável local em uma função. Passar NULL para o construtor, que faz com que a estrutura criar e abrir um temporário `CDatabase` objeto para você. Como alternativa, passe um ponteiro para um `CDatabase` objeto. Use o conjunto de registros dentro da função e deixá-lo a ser destruído automaticamente quando a função for encerrada.

   Quando você passar NULL para um construtor de conjunto de registros, a estrutura usa informações retornadas pelo conjunto de registros `GetDefaultConnect` função de membro para criar um `CDatabase` de objeto e abri-lo. Os assistentes implementam `GetDefaultConnect` para você.

- Se você estiver acessando um conjunto de registros durante o tempo de vida do documento, inserir um ou mais `CRecordset` objetos no seu documento.

   Construa os objetos de conjunto de registros ao inicializar o documento ou conforme necessário. Você pode escrever uma função que retorna um ponteiro para o conjunto de registros, se ele já existe ou cria e abre o conjunto de registros, se ele ainda não existir. Fechar, excluir e recriar o conjunto de registros, conforme necessário ou chamar seu `Requery` função de membro para atualizar os registros.

- Se você estiver acessando uma fonte de dados durante o tempo de vida do documento, inserir uma `CDatabase` do objeto ou armazenar um ponteiro para um `CDatabase` objeto nele.

   O `CDatabase` objeto gerencia uma conexão à fonte de dados. O objeto é criado automaticamente durante a construção de documento, e você chamar seu `Open` função de membro ao inicializar o documento. Quando você constrói objetos de conjunto de registros nas funções de membro de documento, você passa um ponteiro para o documento `CDatabase` objeto. Isso associa cada conjunto de registros com sua fonte de dados. O objeto de banco de dados geralmente é destruído quando o documento é fechado. Os objetos de conjunto de registros normalmente são destruídos quando saírem do escopo de uma função.

##  <a name="_core_other_factors"></a> Outros fatores

Aplicativos baseados em formulário geralmente não têm nenhum uso para o mecanismo de serialização do documento da estrutura, então você pode querer remover, desabilitar ou substituir os **New** e **abrir** comandos na **Arquivo** menu. Consulte o artigo [serialização: Serialização vs. Entrada/saída de banco de dados](../mfc/serialization-serialization-vs-database-input-output.md).

Você também poderá fazer uso de muitas possibilidades de interface do usuário que o framework pode dar suporte. Por exemplo, você pode usar várias `CRecordView` objetos em uma janela separadora, abra vários conjuntos de registros em diferentes várias janelas de filho de MDI (interface MDI) do documento e assim por diante.

Você talvez queira implementar a impressão de tudo o que está no modo de exibição, se ele é um formulário é implementada com `CRecordView` ou alguma outra coisa. Como as classes derivadas `CFormView`, `CRecordView` não dão suporte a impressão, mas você pode substituir o `OnPrint` a função de membro para permitir a impressão. Para obter mais informações, consulte a classe [CFormView](../mfc/reference/cformview-class.md).

Talvez você não queira usar documentos e exibições em todos os. Nesse caso, consulte [MFC: Usando Classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md).

## <a name="see-also"></a>Consulte também

[Classes de banco de dados MFC](../data/mfc-database-classes-odbc-and-dao.md)