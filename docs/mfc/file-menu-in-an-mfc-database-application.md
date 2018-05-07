---
title: Menu de arquivo em um aplicativo de banco de dados MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- File menu
- database applications [MFC], File menu commands
ms.assetid: 92dafb75-c1b3-4860-80a0-87a83bfc36f2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 71e669336e4a23f1a34e0bbd65bd8123e0df3335
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="file-menu-in-an-mfc-database-application"></a>Menu de arquivo em um aplicativo de banco de dados MFC
Se você criar um aplicativo de banco de dados MFC e não usa a serialização, como deve interpretar abrir, fechar, salvar e salvar como comandos no menu arquivo enquanto não houver nenhum diretrizes de estilo para essa pergunta, aqui estão algumas sugestões:  
  
-   Elimine inteiramente o comando Abrir do menu arquivo.  
  
-   Interpretar o comando Abrir como "Abrir banco de dados" e mostrar ao usuário uma lista de fontes de dados que seu aplicativo reconhece.  
  
-   Interpretar o comando Abrir como, talvez, "abrir perfil". Manter aberto para abrir um arquivo serializado, mas usar o arquivo para armazenar um documento serializado que contém informações do "perfil de usuário", como as preferências do usuário, incluindo suas ou sua ID de logon (excluindo, opcionalmente, a senha) e os fonte de dados que mais recentemente trabalhou.  
  
 Assistente de aplicativo MFC dá suporte à criação de um aplicativo com comandos do menu nenhum arquivo relacionados ao documento. Selecione o **exibição sem suporte para arquivo de banco de dados** opção o **suporte do banco de dados** página.  
  
 Para interpretar um comando de menu do arquivo de forma especial, você deve substituir um ou mais manipuladores de comando, principalmente em seu `CWinApp`-classe derivada. Por exemplo, se você substituir completamente `OnFileOpen` (que implementa o `ID_FILE_OPEN` comando) como "Abrir banco de dados:"  
  
-   Não chamar a classe base versão `OnFileOpen`, uma vez que você está substituindo completamente implementação do padrão da estrutura do comando.  
  
-   Use o manipulador para exibir uma caixa de diálogo lista de fontes de dados. Você pode exibir uma caixa de diálogo chamando `CDatabase::OpenEx` ou `CDatabase::Open` com o parâmetro **nulo**. Isso abre uma caixa de diálogo ODBC que exibe todas as fontes de dados disponíveis no computador do usuário.  
  
-   Como os aplicativos de banco de dados geralmente não salva um documento inteiro, você provavelmente desejará remover salvar e salvar como implementações a menos que você use um documento serializado para armazenar informações de perfil. Caso contrário, você pode implementar o comando Salvar como, por exemplo, "confirmar transação." Consulte [22 de observação técnica](../mfc/tn022-standard-commands-implementation.md) para obter mais informações sobre a substituição desses comandos.  
  
## <a name="see-also"></a>Consulte também  
 [Serialização: Serialização vs. Banco de dados de entrada/saída](../mfc/serialization-serialization-vs-database-input-output.md)

