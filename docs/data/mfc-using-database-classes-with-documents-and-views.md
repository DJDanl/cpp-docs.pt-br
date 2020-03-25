---
title: 'MFC: usando classes de banco de dados com documentos e exibições'
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
ms.openlocfilehash: e2b073b20b9518667b43c30e7ee3199a84a3ad38
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213376"
---
# <a name="mfc-using-database-classes-with-documents-and-views"></a>MFC: usando classes de banco de dados com documentos e exibições

Você pode usar as classes de banco de dados MFC com ou sem a arquitetura de documento/exibição. Este tópico enfatiza o trabalho com documentos e exibições. Ele explica:

- [Como escrever um aplicativo baseado em formulário](#_core_writing_a_form.2d.based_application) usando um objeto `CRecordView` como a exibição principal no documento.

- [Como usar objetos Recordset em seus documentos e exibições](#_core_using_recordsets_in_documents_and_views).

- [Outras considerações](#_core_other_factors).

Para alternativas, consulte [MFC: usando classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md).

##  <a name="writing-a-form-based-application"></a><a name="_core_writing_a_form.2d.based_application"></a>Escrevendo um aplicativo baseado em formulário

Muitos aplicativos de acesso a dados são baseados em formulários. A interface do usuário é um formulário que contém controles nos quais o usuário examina, insere ou edita dados. Para tornar o formulário do aplicativo baseado, use a classe `CRecordView`. Quando você executa o assistente de aplicativo MFC e seleciona tipo de cliente **ODBC** na página de **suporte do banco de dados** , o projeto usa `CRecordView` para a classe de exibição.

Em um aplicativo baseado em formulário, cada objeto de exibição de registro armazena um ponteiro para um objeto `CRecordset`. O mecanismo de intercâmbio de campo de registro (suporte RFX) da estrutura troca dados entre o conjunto de registros e a fonte de dados. O mecanismo de intercâmbio de dados de caixa de diálogo (campo DDX) troca dados entre os membros de dados de campo do objeto Recordset e os controles no formulário. `CRecordView` também fornece funções de manipulador de comando padrão para navegar de registro para registro no formulário.

Para criar um aplicativo baseado em formulário com o assistente de aplicativo, consulte [criando um aplicativo MFC baseado em formulários](../mfc/reference/creating-a-forms-based-mfc-application.md) e [suporte a banco de dados, assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md).

Para obter uma discussão completa sobre formulários, consulte [exibições de registro](../data/record-views-mfc-data-access.md).

##  <a name="using-recordsets-in-documents-and-views"></a><a name="_core_using_recordsets_in_documents_and_views"></a>Usando conjuntos de registros em documentos e exibições

Muitos aplicativos simples baseados em formulário não precisam de documentos. Se seu aplicativo for mais complexo, provavelmente você desejará usar um documento como um proxy para o banco de dados, armazenando um objeto de `CDatabase` que se conecta à fonte de dado. Normalmente, os aplicativos baseados em formulário armazenam um ponteiro para um objeto Recordset na exibição. Outros tipos de aplicativos de banco de dados armazenam conjuntos de registros e `CDatabase` objeto no documento. Aqui estão algumas possibilidades para usar documentos em aplicativos de banco de dados:

- Se você estiver acessando um conjunto de registros em um contexto local, crie um objeto `CRecordset` localmente em funções de membro do documento ou exibição, conforme necessário.

   Declare um objeto Recordset como uma variável local em uma função. Passe NULL para o construtor, o que faz com que a estrutura crie e abra um objeto de `CDatabase` temporário para você. Como alternativa, passe um ponteiro para um objeto `CDatabase`. Use o conjunto de registros dentro da função e permita que ele seja destruído automaticamente quando a função sair.

   Quando você passa NULL para um construtor de conjunto de registros, a estrutura usa as informações retornadas pela função de membro `GetDefaultConnect` do conjunto de registros para criar um objeto de `CDatabase` e abri-lo. Os assistentes implementam `GetDefaultConnect` para você.

- Se você estiver acessando um conjunto de registros durante o tempo de vida do seu documento, insira um ou mais objetos `CRecordset` em seu documento.

   Construa os objetos do conjunto de registros ao inicializar o documento ou conforme necessário. Você pode escrever uma função que retorna um ponteiro para o conjunto de registros se ele já existir ou construir e abrir o conjunto de registros se ele ainda não existir. Feche, exclua e recrie o conjunto de registros conforme necessário ou chame sua função de membro `Requery` para atualizar os registros.

- Se você estiver acessando uma fonte de dados durante o tempo de vida do seu documento, insira um `CDatabase` objeto ou armazene um ponteiro para um objeto `CDatabase` nele.

   O objeto `CDatabase` gerencia uma conexão com sua fonte de dados. O objeto é construído automaticamente durante a construção do documento e você chama sua função de membro `Open` ao inicializar o documento. Ao construir objetos de conjunto de registros em funções de membro de documento, você passa um ponteiro para o objeto de `CDatabase` do documento. Isso associa cada conjunto de registros à sua fonte de dados. O objeto de banco de dados geralmente é destruído quando o documento é fechado. Os objetos Recordset normalmente são destruídos quando saem do escopo de uma função.

##  <a name="other-factors"></a><a name="_core_other_factors"></a>Outros fatores

Aplicativos baseados em formulário geralmente não têm nenhum uso para o mecanismo de serialização de documentos da estrutura, portanto, talvez você queira remover, desabilitar ou substituir os comandos **novo** e **abrir** no menu **arquivo** . Consulte o artigo [serialização: serialização versus entrada/saída do banco de dados](../mfc/serialization-serialization-vs-database-input-output.md).

Talvez você também queira usar as várias possibilidades de interface do usuário para as quais a estrutura pode dar suporte. Por exemplo, você pode usar vários objetos `CRecordView` em uma janela separadora, abrir vários conjuntos de registros em diferentes janelas filhas de MDI (interface de vários documentos) e assim por diante.

Talvez você queira implementar a impressão de qualquer coisa que esteja em sua exibição, seja um formulário implementado com `CRecordView` ou outra coisa. Como classes derivadas de `CFormView`, `CRecordView` não oferece suporte à impressão, mas você pode substituir a função membro `OnPrint` para permitir a impressão. Para obter mais informações, consulte Class [CFormView](../mfc/reference/cformview-class.md).

Talvez você não queira usar documentos e exibições. Nesse caso, consulte [MFC: usando classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md).

## <a name="see-also"></a>Confira também

[Classes de banco de dados MFC](../data/mfc-database-classes-odbc-and-dao.md)
