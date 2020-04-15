---
title: 'TN048: escrevendo programas de instalação e administração ODBC para aplicativos de banco de dados MFC'
ms.date: 11/04/2016
helpviewer_keywords:
- installing ODBC
- ODBC, installing
- setup, ODBC setup programs
- TN048
- ODBC, and MFC
- MFC, database applications
ms.assetid: d456cdd4-0513-4a51-80c0-9132b66115ce
ms.openlocfilehash: d25520c4ffc805701dfe6b51192f8078e2fa300f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365475"
---
# <a name="tn048-writing-odbc-setup-and-administration-programs-for-mfc-database-applications"></a>TN048: escrevendo programas de instalação e administração ODBC para aplicativos de banco de dados MFC

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Os aplicativos que usam classes de banco de dados MFC precisarão de um programa de configuração que instale componentes ODBC. Eles também podem precisar de um programa de administração ODBC que recuperará informações sobre os drivers disponíveis, para especificar drivers padrão e configurar fontes de dados. Esta nota descreve o uso da API do Instalador ODBC para escrever esses programas.

## <a name="writing-an-odbc-setup-program"></a><a name="_mfcnotes_writing_an_odbc_setup_program"></a>Escrevendo um programa de configuração da ODBC

Um aplicativo de banco de dados MFC requer o ODBC Driver Manager (ODBC). DLL) e drivers ODBC para ser capaz de chegar às fontes de dados. Muitos drivers ODBC também requerem DLLs adicionais de rede e comunicação. A maioria dos drivers ODBC enviam um programa de configuração que instalará os componentes ODBC necessários. Os desenvolvedores de aplicativos que usam classes de banco de dados MFC podem:

- Conte com os programas de configuração específicos do driver para instalar componentes ODBC. Isso não exigirá mais trabalho por parte do desenvolvedor — você pode simplesmente redistribuir o programa de configuração do driver.

- Alternativamente, você pode escrever seu próprio programa de configuração, que instalará o driver manager e o driver.

A API do instalador ODBC pode ser usada para gravar programas de configuração específicos do aplicativo. As funções na API do instalador são implementadas pelo instalador ODBC DLL — ODBCINST. DLL em Windows de 16 bits e ODBCCP32. DLL no Win32. Um aplicativo `SQLInstallODBC` pode chamar o instalador DLL, que instalará o gerenciador de driver ODBC, drivers ODBC e quaisquer tradutores necessários. Em seguida, registra os drivers e tradutores instalados no ODBCINST. Arquivo INI (ou o registro, no NT). `SQLInstallODBC`requer o caminho completo para o ODBC. Arquivo INF, que contém a lista de drivers a serem instalados e descreve os arquivos que compõem cada driver. Também contém informações semelhantes sobre o gerente do motorista e tradutores. Odbc. Os arquivos INF são normalmente fornecidos por desenvolvedores de drivers.

Um programa também pode instalar componentes ODBC individuais. Para instalar o Driver Manager, `SQLInstallDriverManager` um programa primeiro solicita no instalador DLL para obter o diretório de destino do Driver Manager. Este é geralmente o diretório no qual os DLLs do Windows residem. Em seguida, o programa usa as informações na seção [ODBC Driver Manager] do ODBC. Arquivo INF para copiar o Gerenciador de driver e arquivos relacionados do disco de instalação para este diretório. Para instalar um driver individual, `SQLInstallDriver` um programa primeiro chama o instalador dLL para adicionar a especificação do driver ao ODBCINST. Arquivo INI (ou o registro, no NT). `SQLInstallDriver`retorna o diretório de destino do driver — geralmente o diretório no qual residem os DLLs do Windows. Em seguida, o programa usa as informações na seção de driver do ODBC. Arquivo INF para copiar o DLL do driver e arquivos relacionados do disco de instalação para este diretório.

Para mais informações sobre a ODBC. INF, ODBCINST. INI e usando a API do instalador, consulte A *Referência do Programador* ODBC SDK, Capítulo 19, Instalação do Software ODBC.

## <a name="writing-an-odbc-administrator"></a><a name="_mfcnotes_writing_an_odbc_administrator"></a>Escrevendo um administrador oDBC

Um aplicativo de banco de dados MFC pode configurar e configurar fontes de dados ODBC de duas maneiras, da seguinte forma:

- Use o administrador ODBC (disponível como um programa ou como item do Painel de Controle).

- Crie seu próprio programa para configurar fontes de dados.

Um programa que configura fontes de dados faz chamadas de função para o instalador DLL. O instalador DLL chama uma Configuração DLL para configurar uma fonte de dados. Há uma configuração DLL para cada driver; pode ser o driver DLL em si, ou um DLL separado. A configuração DLL solicita ao usuário informações que o driver precisa para se conectar à fonte de dados e ao tradutor padrão, se suportado. Em seguida, ele chama o instalador Dell e APIs do Windows para registrar essas informações no ODBC. Arquivo INI (ou registro).

Para exibir uma caixa de diálogo com a qual um usuário `SQLManageDataSources` pode adicionar, modificar e excluir fontes de dados, um programa chama no instalador DLL. Esta função é invocada quando o instalador DLL é chamado do Painel de Controle. Para adicionar, modificar ou excluir `SQLManageDataSources` uma `ConfigDSN` fonte de dados, chama na configuração DLL para o driver associado a essa fonte de dados. Para adicionar, modificar ou excluir diretamente fontes `SQLConfigDataSource` de dados, um programa chama no instalador DLL. O programa passa o nome da fonte de dados e uma opção que especifica a ação a ser tomada. `SQLConfigDataSource`chama `ConfigDSN` a configuração DLL e passa-a os argumentos de `SQLConfigDataSource`.

Para obter mais informações, consulte a *referência do programador* ODBC SDK, o capítulo 23, a referência da função DLL de configuração e o capítulo 24, referência da função do instalador DLL.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
