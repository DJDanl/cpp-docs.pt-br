---
title: Menu de arquivo em um aplicativo de banco de dados MFC
ms.date: 11/04/2016
helpviewer_keywords:
- File menu
- database applications [MFC], File menu commands
ms.assetid: 92dafb75-c1b3-4860-80a0-87a83bfc36f2
ms.openlocfilehash: 6c9a195a81423417809b65b5edce32027071ad2e
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57279114"
---
# <a name="file-menu-in-an-mfc-database-application"></a>Menu de arquivo em um aplicativo de banco de dados MFC

Se você cria um aplicativo de banco de dados do MFC e não usa a serialização, como deve interpretar a abrir, fechar, salvar e salvar como de comandos no menu Arquivo Embora não haja nenhum diretrizes de estilo para essa pergunta, aqui estão algumas sugestões:

- Elimine completamente o comando de abertura do menu arquivo.

- Interpretar o comando Abrir como "banco de dados aberto" e mostrar ao usuário uma lista de fontes de dados que seu aplicativo reconheça.

- Interpretar o comando Abrir como, talvez, "abrir perfil". Manter aberto, mas a abertura de um arquivo serializado, use o arquivo para armazenar um documento serializado que contém informações de "perfil do usuário", como as preferências do usuário, incluindo seu ou sua ID de logon (excluindo, opcionalmente, a senha) e os fonte de dados ele ou ela mais recentemente trabalhou com.

O Assistente de aplicativo do MFC dá suporte à criação de um aplicativo com nenhum comando de menu Arquivo relacionadas a documentos. Selecione o **modo de exibição sem suporte a arquivos de banco de dados** opção a **dar suporte a banco de dados** página.

Para interpretar um comando de menu de arquivo de forma especial, você deve substituir um ou mais manipuladores de comandos, principalmente em seu `CWinApp`-classe derivada. Por exemplo, se você substituir completamente `OnFileOpen` (que implementa o `ID_FILE_OPEN` comando) para significar "Abrir banco de dados:"

- Não chame a versão da classe base do `OnFileOpen`, uma vez que você está substituindo completamente implementação do padrão da estrutura do comando.

- Use o manipulador para exibir uma caixa de diálogo listando as fontes de dados. Você pode exibir uma caixa de diálogo chamando `CDatabase::OpenEx` ou `CDatabase::Open` com o parâmetro **nulo**. Isso abre uma caixa de diálogo ODBC que exibe todas as fontes de dados disponíveis no computador do usuário.

- Como aplicativos de banco de dados normalmente não salva um documento inteiro, provavelmente vai querer remover o salvamento e salve como implementações, a menos que um documento serializado é usado para armazenar informações de perfil. Caso contrário, você pode implementar o comando Salvar como, por exemplo, "confirmar transação." Ver [22 de observação técnica](../mfc/tn022-standard-commands-implementation.md) para obter mais informações sobre a substituição desses comandos.

## <a name="see-also"></a>Consulte também

[Serialização: Serialização vs. Banco de dados de entrada/saída](../mfc/serialization-serialization-vs-database-input-output.md)
