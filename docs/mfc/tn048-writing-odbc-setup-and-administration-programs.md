---
title: "TN048: Escrevendo programas de administração e configuração do ODBC para aplicativos de banco de dados MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.mfc.odbc
dev_langs: C++
helpviewer_keywords:
- installing ODBC
- ODBC, installing
- setup, ODBC setup programs
- TN048
- ODBC, and MFC
- MFC, database applications
ms.assetid: d456cdd4-0513-4a51-80c0-9132b66115ce
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3ec19e3c03d88fa088622c7ed8a5b4efeed0014b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn048-writing-odbc-setup-and-administration-programs-for-mfc-database-applications"></a>TN048: escrevendo programas de instalação e administração ODBC para aplicativos de banco de dados MFC
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Aplicativos que usam as classes de banco de dados MFC precisará de um programa de instalação que instala componentes ODBC. Eles também será necessário um programa de administração do ODBC que recupera informações sobre os drivers disponíveis, para especificar drivers padrão e configurar fontes de dados. Esta anotação descreve o uso da API do instalador ODBC para gravar esses programas.  
  
##  <a name="_mfcnotes_writing_an_odbc_setup_program"></a>Escrever um programa de instalação do ODBC  
 Um aplicativo de banco de dados MFC requer o Gerenciador de Driver ODBC (ODBC. DLL) e drivers ODBC para ser capaz de obter a fontes de dados. Muitos drivers ODBC também exigem DLLs de comunicação e de rede adicionais. A maioria dos drivers ODBC fornecidos com um programa de instalação instalará os componentes necessários do ODBC. Os desenvolvedores de aplicativos usando classes de banco de dados MFC podem:  
  
-   Contam com os programas de instalação de driver específico para instalar os componentes ODBC. Isso exigirá que nenhum outro trabalho na parte do desenvolvedor — você pode redistribuir apenas o programa de instalação do driver.  
  
-   Como alternativa, você pode escrever seu próprio programa de instalação, que instalará o Gerenciador de driver e o driver.  
  
 A API do instalador ODBC pode ser usada para gravar programas de instalação específicas do aplicativo. As funções no instalador do API são implementadas pelo instalador ODBC DLL — ODBCINST. DLL no Windows de 16 bits e ODBCCP32. DLL Win32. Um aplicativo pode chamar **SQLInstallODBC** do instalador de DLL, que irá instalar o Gerenciador de driver ODBC, os drivers ODBC e qualquer necessário tradutores. Em seguida, registra os drivers instalados e tradutores no ODBCINST. O arquivo INI (ou o registro, no NT). **SQLInstallODBC** requer o caminho completo para o ODBC. Arquivo INF, que contém a lista de drivers a serem instalados e descreve os arquivos que compõem cada driver. Ele também contém informações semelhantes sobre o Gerenciador de driver e tradutores. ODBC. Normalmente, os arquivos INF são fornecidos por desenvolvedores de driver.  
  
 Um programa também pode instalar componentes individuais do ODBC. Para instalar o Gerenciador de Driver, um programa primeiro chama **SQLInstallDriverManager** no instalador do DLL para obter o diretório de destino para o Gerenciador de Driver. Isso geralmente é o diretório no qual residem DLLs do Windows. O programa, em seguida, usa as informações na seção [ODBC Driver Manager] do ODBC. Arquivo INF para copiar o Gerenciador de Driver e arquivos relacionados do disco de instalação para este diretório. Para instalar um driver individual, um programa primeiro chama **SQLInstallDriver** no instalador do DLL para adicionar a especificação de driver para o ODBCINST. O arquivo INI (ou o registro, no NT). **SQLInstallDriver** retorna o diretório de destino do driver — geralmente o diretório no qual residem DLLs do Windows. O programa, em seguida, usa as informações na seção do driver ODBC. Arquivo INF para copiar os arquivos relacionados e a DLL do driver do disco de instalação para este diretório.  
  
 Para obter mais informações sobre ODBC. INF, ODBCINST. INI e usar o instalador API, consulte o SDK do ODBC *referência do programador,* capítulo 19, instalando o Software de ODBC.  
  
##  <a name="_mfcnotes_writing_an_odbc_administrator"></a>Escrevendo um administrador ODBC  
 Um aplicativo de banco de dados MFC pode instalar e configurar fontes de dados ODBC em uma das duas maneiras, da seguinte maneira:  
  
-   Use o administrador ODBC (disponível como um programa ou um item do painel de controle).  
  
-   Crie seu próprio programa para configurar fontes de dados.  
  
 Um programa que configura fontes de dados faz chamadas de função para a DLL do instalador. O instalador DLL chama um DLL para configurar uma fonte de dados de configuração. Há uma DLL de configuração para cada driver. pode ser o própria DLL do driver ou uma DLL separada. A DLL de instalação solicitará ao usuário para obter informações que o driver precisa se conectar à fonte de dados e o conversor padrão, se houver suporte. Em seguida, ele chama o instalador DLL e APIs do Windows para registrar essas informações no ODBC. O arquivo INI (ou registro).  
  
 Para exibir uma caixa de diálogo com a qual um usuário pode adicionar, modificar e excluir fontes de dados, um programa chama **SQLManageDataSources** no instalador do DLL. Esta função é invocada quando o instalador DLL é chamado de painel de controle. Para adicionar, modificar ou excluir uma fonte de dados **SQLManageDataSources** chamadas **ConfigDSN** na configuração de DLL para o driver associado a essa fonte de dados. Para adicionar, modificar ou excluir dados diretamente fontes, um programa chama **SQLConfigDataSource** no instalador do DLL. O programa passa o nome da fonte de dados e uma opção que especifica a ação a ser tomada. **SQLConfigDataSource** chamadas **ConfigDSN** na configuração da DLL e passa os argumentos de **SQLConfigDataSource**.  
  
 Para obter mais informações, consulte o SDK do ODBC *referência do programador,* capítulo 23, referência de função de DLL de instalação e capítulo 24, referência de função de DLL do instalador.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

