---
title: Menu de arquivo em um aplicativo de banco de dados MFC
ms.date: 11/04/2016
helpviewer_keywords:
- File menu
- database applications [MFC], File menu commands
ms.assetid: 92dafb75-c1b3-4860-80a0-87a83bfc36f2
ms.openlocfilehash: fbbb4382749278708e8e758f79a618d5cad0549e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615696"
---
# <a name="file-menu-in-an-mfc-database-application"></a>Menu de arquivo em um aplicativo de banco de dados MFC

Se você criar um aplicativo de banco de dados MFC e não usar a serialização, como você deve interpretar os comandos abrir, fechar, salvar e salvar como no menu arquivo, embora não haja diretrizes de estilo para essa pergunta, aqui estão algumas sugestões:

- Elimine inteiramente o comando abrir do menu arquivo.

- Interprete o comando Open como "Open Database" e mostre ao usuário uma lista de fontes de dados que seu aplicativo reconhece.

- Interprete o comando Open como, talvez, "Open Profile". Mantenha aberta para abrir um arquivo serializado, mas use o arquivo para armazenar um documento serializado contendo informações de "perfil do usuário", como as preferências do usuário, incluindo sua ID de logon (opcionalmente, excluindo a senha) e a fonte de dados com a qual ela trabalhou mais recentemente.

O assistente de aplicativo do MFC dá suporte à criação de um aplicativo sem comandos de menu de arquivo relacionados a documentos. Selecione a opção **exibição de banco de dados sem suporte a arquivos** na página suporte do banco de **dados** .

Para interpretar um comando de menu de arquivo de forma especial, você deve substituir um ou mais manipuladores de comandos, principalmente na `CWinApp` classe derivada. Por exemplo, se você substituir completamente `OnFileOpen` (que implementa o `ID_FILE_OPEN` comando) para significar "Abrir banco de dados:"

- Não chame a versão da classe base do `OnFileOpen` , pois você está substituindo completamente a implementação padrão do comando da estrutura.

- Em vez disso, use o manipulador para exibir uma caixa de diálogo listando fontes de dados. Você pode exibir tal caixa de diálogo chamando `CDatabase::OpenEx` ou `CDatabase::Open` com o parâmetro **NULL**. Isso abre uma caixa de diálogo ODBC que exibe todas as fontes de dados disponíveis na máquina do usuário.

- Como os aplicativos de banco de dados normalmente não salvam um documento inteiro, você provavelmente desejará remover as implementações salvar e salvar como, a menos que use um documento serializado para armazenar informações de perfil. Caso contrário, você pode implementar o comando Salvar como, por exemplo, "confirmar transação." Consulte a [Nota técnica 22](tn022-standard-commands-implementation.md) para obter mais informações sobre como substituir esses comandos.

## <a name="see-also"></a>Consulte também

[Serialização: serialização em comparação com entrada/saída do banco de dados](serialization-serialization-vs-database-input-output.md)
