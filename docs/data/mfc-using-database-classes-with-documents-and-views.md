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
ms.openlocfilehash: 9e071e0cc25492073cd74ed517284476b6e49ef8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368896"
---
# <a name="mfc-using-database-classes-with-documents-and-views"></a>MFC: usando classes de banco de dados com documentos e exibições

Você pode usar as classes de banco de dados Do MFC com ou sem a arquitetura document/view. Este tópico enfatiza o trabalho com documentos e pontos de vista. Explica:

- [Como escrever um aplicativo baseado](#_core_writing_a_form.2d.based_application) `CRecordView` em formulário usando um objeto como exibição principal em seu documento.

- [Como usar objetos de conjunto de registros em seus documentos e visualizações.](#_core_using_recordsets_in_documents_and_views)

- [Outras considerações.](#_core_other_factors)

Para alternativas, consulte [MFC: Usando classes de banco de dados sem documentos e visualizações.](../data/mfc-using-database-classes-without-documents-and-views.md)

## <a name="writing-a-form-based-application"></a><a name="_core_writing_a_form.2d.based_application"></a>Escrevendo um aplicativo baseado em formulário

Muitos aplicativos de acesso a dados são baseados em formulários. A interface do usuário é um formulário que contém controles nos quais o usuário examina, insere ou emite dados. Para tornar seu formulário de `CRecordView`inscrição baseado, use classe . Quando você executa o Assistente de Aplicativo MFC e seleciona o `CRecordView` tipo de cliente **ODBC** na página de suporte ao banco de **dados,** o projeto é usa para a classe de exibição.

Em um aplicativo baseado em formulário, cada objeto `CRecordset` de exibição de registro armazena um ponteiro para um objeto. O mecanismo de troca de campo de registro (RFX) do framework troca dados entre o conjunto de registros e a fonte de dados. O mecanismo de troca de dados de diálogo (DDX) troca dados entre os membros de dados de campo do objeto recordset e os controles no formulário. `CRecordView`também fornece funções padrão de manipulador de comando para navegar do registro para gravar no formulário.

Para criar um aplicativo baseado em formulário com o assistente do aplicativo, consulte Criando um Suporte de aplicativo e banco de dados [baseado em formulários,](../mfc/reference/creating-a-forms-based-mfc-application.md) [MFC Application Wizard](../mfc/reference/database-support-mfc-application-wizard.md).

Para uma discussão completa de formulários, consulte [Record Views](../data/record-views-mfc-data-access.md).

## <a name="using-recordsets-in-documents-and-views"></a><a name="_core_using_recordsets_in_documents_and_views"></a>Usando conjuntos de registros em documentos e visualizações

Muitos aplicativos simples baseados em formulários não precisam de documentos. Se o seu aplicativo for mais complexo, você provavelmente deseja usar um `CDatabase` documento como proxy para o banco de dados, armazenando um objeto que se conecta à fonte de dados. Aplicativos baseados em formulário geralmente armazenam um ponteiro para um objeto de conjunto de registros na exibição. Outros tipos de aplicativos de `CDatabase` banco de dados armazenam conjuntos de registros e objetos no documento. Aqui estão algumas possibilidades para usar documentos em aplicativos de banco de dados:

- Se você estiver acessando um conjunto `CRecordset` de registros em um contexto local, crie um objeto localmente nas funções de membro do documento ou na exibição, conforme necessário.

   Declare um objeto de conjunto de registros como uma variável local em uma função. Passe NULL para o construtor, o que faz `CDatabase` com que a estrutura crie e abra um objeto temporário para você. Como alternativa, passe um `CDatabase` ponteiro para um objeto. Use o conjunto de registros dentro da função e deixe-o ser destruído automaticamente quando a função sair.

   Quando você passa NULL para um construtor de conjunto de registros, `GetDefaultConnect` a estrutura usa `CDatabase` informações retornadas pela função de membro do conjunto de registros para criar um objeto e abri-lo. Os magos `GetDefaultConnect` implementam para você.

- Se você estiver acessando um conjunto de registros durante `CRecordset` a vida útil do seu documento, incorpore um ou mais objetos em seu documento.

   Construa os objetos do conjunto de registros quando você inicializar o documento ou conforme necessário. Você pode escrever uma função que retorna um ponteiro para o conjunto de registros se ele já existir ou construir e abrir o conjunto de registros se ele ainda não existir. Fechar, excluir e recriar o conjunto de `Requery` registros conforme necessário ou chamar sua função de membro para atualizar os registros.

- Se você estiver acessando uma fonte de dados `CDatabase` durante a vida `CDatabase` útil do seu documento, incorpore um objeto ou armazene um ponteiro para um objeto nele.

   O `CDatabase` objeto gerencia uma conexão com sua fonte de dados. O objeto é construído automaticamente durante a construção `Open` do documento, e você chama sua função de membro quando você inicializa o documento. Quando você constrói objetos de conjunto de registros nas funções `CDatabase` do membro do documento, você passa um ponteiro para o objeto do documento. Isso associa cada conjunto de registros com sua fonte de dados. O objeto do banco de dados geralmente é destruído quando o documento fecha. Os objetos do conjunto de registros são tipicamente destruídos quando saem do escopo de uma função.

## <a name="other-factors"></a><a name="_core_other_factors"></a>Outros fatores

Os aplicativos baseados em formulário geralmente não têm qualquer uso para o mecanismo de serialização de documentos da estrutura, então você pode querer remover, desativar ou substituir os comandos **Novo** e **Abrir** no menu **Arquivo.** Veja o artigo [Serialização: Serialização vs. Entrada/Saída do Banco de Dados](../mfc/serialization-serialization-vs-database-input-output.md).

Você também pode querer fazer uso das muitas possibilidades de interface de usuário que a estrutura pode suportar. Por exemplo, você `CRecordView` pode usar vários objetos em uma janela de divisor, abrir vários conjuntos de registros em diferentes janelas de crianças de interface de documento múltiplo (MDI) e assim por diante.

Você pode querer implementar a impressão do que está em `CRecordView` sua opinião, seja um formulário implementado com ou outra coisa. Como classes `CFormView`derivadas, `CRecordView` não suporta impressão, mas `OnPrint` você pode substituir a função do membro para permitir a impressão. Para obter mais informações, consulte classe [CFormView](../mfc/reference/cformview-class.md).

Você pode não querer usar documentos e visualizações. Nesse caso, consulte [MFC: Usando classes de banco de dados sem documentos e visualizações.](../data/mfc-using-database-classes-without-documents-and-views.md)

## <a name="see-also"></a>Confira também

[Classes de banco de dados MFC](../data/mfc-database-classes-odbc-and-dao.md)
