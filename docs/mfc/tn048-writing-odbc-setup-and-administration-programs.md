---
title: 'TN048: Escrever programas de administração e a instalação do ODBC para aplicativos de banco de dados MFC'
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.odbc
helpviewer_keywords:
- installing ODBC
- ODBC, installing
- setup, ODBC setup programs
- TN048
- ODBC, and MFC
- MFC, database applications
ms.assetid: d456cdd4-0513-4a51-80c0-9132b66115ce
ms.openlocfilehash: 2904ceb626fd1bfad0b24026deb08f2c5dcbcd4a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62305327"
---
# <a name="tn048-writing-odbc-setup-and-administration-programs-for-mfc-database-applications"></a>TN048: Escrever programas de administração e a instalação do ODBC para aplicativos de banco de dados MFC

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Aplicativos que usam classes de banco de dados do MFC serão necessário um programa de instalação que instala os componentes ODBC. Eles também terão um programa de administração do ODBC que irá recuperar informações sobre os drivers disponíveis, para especificar os drivers padrão e configurar fontes de dados. Essa observação descreve o uso da API do instalador ODBC para gravar esses programas.

##  <a name="_mfcnotes_writing_an_odbc_setup_program"></a> Escrever um programa de instalação do ODBC

Um aplicativo de banco de dados MFC requer o Gerenciador de Driver de ODBC (ODBC. DLL) e drivers ODBC para ser capaz de obter a fontes de dados. Muitos drivers ODBC também exigem DLLs adicionais de rede e comunicação. A maioria dos drivers ODBC são fornecidos com um programa de instalação instalará os componentes necessários do ODBC. Os desenvolvedores de aplicativos usando classes de banco de dados MFC podem:

- Contar os programas de configuração específica do driver para instalar os componentes ODBC. Isso exigirá que nenhum outro trabalho de parte do desenvolvedor — você apenas pode redistribuir o programa de instalação do driver.

- Como alternativa, você pode escrever seu próprio programa de instalação, que instalará o Gerenciador de driver e o driver.

A API do instalador ODBC pode ser usada para gravar programas de instalação específicas do aplicativo. As funções no instalador do API são implementadas pelo instalador do ODBC DLL — ODBCINST. DLL no Windows de 16 bits e ODBCCP32. DLL no Win32. Um aplicativo pode chamar `SQLInstallODBC` no instalador do DLL, que instalará o Gerenciador de driver ODBC, drivers ODBC e qualquer necessário tradutores. Em seguida, em que ele registra os drivers instalados e tradutores no ODBCINST. O arquivo INI (ou o registro, no NT). `SQLInstallODBC` requer o caminho completo para o ODBC. Arquivo INF, que contém a lista de drivers a serem instalados e descreve os arquivos que compõem cada driver. Ele também contém informações semelhantes sobre o Gerenciador de driver e tradutores. ODBC. Arquivos INF geralmente são fornecidos por desenvolvedores de driver.

Um programa também pode instalar componentes individuais do ODBC. Para instalar o Gerenciador de Driver, um programa primeiro chama `SQLInstallDriverManager` no instalador do DLL para obter o diretório de destino para o Gerenciador de Driver. Isso geralmente é o diretório no qual residem DLLs do Windows. O programa, em seguida, usa as informações na seção [ODBC Driver Manager] do ODBC. Arquivo INF para copiar o Gerenciador de Driver e os arquivos relacionados do disco de instalação para este diretório. Para instalar um driver individual, um programa primeiro chama `SQLInstallDriver` no instalador do DLL para adicionar a especificação de driver para o ODBCINST. O arquivo INI (ou o registro, no NT). `SQLInstallDriver` Retorna o diretório de destino do driver — geralmente o diretório no qual residem DLLs do Windows. O programa, em seguida, usa as informações na seção do driver ODBC. Arquivo INF para copiar a DLL do driver e os arquivos relacionados do disco de instalação para este diretório.

Para obter mais informações sobre ODBC. INF, ODBCINST. INI e usando o instalador de API, consulte o SDK do ODBC *referência do programador,* capítulo 19, instalando o Software de ODBC.

##  <a name="_mfcnotes_writing_an_odbc_administrator"></a> Escrevendo um administrador ODBC

Um aplicativo de banco de dados do MFC pode instalar e configurar fontes de dados ODBC em uma das duas maneiras, da seguinte maneira:

- Use o administrador de ODBC (disponível como um programa ou como um item do painel de controle).

- Crie seu próprio programa para configurar fontes de dados.

Um programa que configura fontes de dados faz chamadas de função para a DLL do instalador. A DLL do instalador chama uma DLL para configurar uma fonte de dados de configuração. Há uma DLL de configuração para cada driver; pode ser a própria DLL do driver ou uma DLL separada. A DLL de instalação solicita ao usuário para informações que o driver precisa se conectar à fonte de dados e o conversor padrão, se houver suporte. Em seguida, chama o instalador DLL e APIs do Windows para registrar essas informações no ODBC. O arquivo INI (ou registro).

Para exibir uma caixa de diálogo com a qual um usuário pode adicionar, modificar e excluir fontes de dados, um programa chama `SQLManageDataSources` no instalador do DLL. Essa função é invocada quando o instalador do DLL é chamado de painel de controle. Para adicionar, modificar ou excluir uma fonte de dados `SQLManageDataSources` chamadas `ConfigDSN` na configuração de DLL para o driver associado a essa fonte de dados. Para adicionar, modificar ou excluir os dados diretamente fontes, as chamadas de um programa `SQLConfigDataSource` no instalador do DLL. O programa passa o nome da fonte de dados e uma opção que especifica a ação a ser tomada. `SQLConfigDataSource` chamadas `ConfigDSN` na configuração da DLL e a passa os argumentos de `SQLConfigDataSource`.

Para obter mais informações, consulte o SDK do ODBC *referência do programador,* capítulo 23, a referência de função de DLL de instalação e o capítulo 24, referência de função de DLL do instalador.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
