---
title: 'Fonte de dados: Configurando programaticamente uma fonte de dados ODBC | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- SQLConfigDataSource
dev_langs:
- C++
helpviewer_keywords:
- ODBC data sources, configuring
- SQLConfigDataSource method example
- ODBC connections, configuring
- configuring ODBC data sources
ms.assetid: b8cabe9b-9e12-4d73-ae36-7cb12dee3213
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ac5756452a8b1c2d5dbf2f27ac7d3e1a8b069ca2
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="data-source-programmatically-configuring-an-odbc-data-source"></a>Fonte de dados: configurando programaticamente uma fonte de dados ODBC
Este tópico explica como você pode configurar nomes de fonte de dados de conectividade de banco de dados aberto (ODBC) por meio de programação. Isso fornece flexibilidade para acessar dados sem forçar o usuário usar explicitamente o administrador ODBC ou outros programas para especificar os nomes de fontes de dados.  
  
 Normalmente, um usuário executa o administrador ODBC para criar uma fonte de dados se o sistema de gerenciamento de banco de dados associado (DBMS) dá suporte a esta operação.  
  
 Ao criar uma fonte de dados ODBC do Microsoft Access por meio do administrador de ODBC, você terá duas opções: você pode selecionar um arquivo. mdb existente ou você pode criar um novo arquivo. mdb. Não há nenhuma maneira programática de criar o arquivo. mdb do seu aplicativo de ODBC do MFC. Portanto, se seu aplicativo requer que você coloque os dados em uma fonte de dados do Microsoft Access (arquivo. mdb), você provavelmente deseja ter um arquivo. mdb vazio que você pode usar ou copiar sempre que precisar.  
  
 No entanto, muitos DBMSs permitem que a criação da fonte de dados através de programação. Algumas fontes de dados mantêm uma especificação de diretório para bancos de dados. Ou seja, um diretório é a fonte de dados e cada tabela na fonte de dados é armazenada em um arquivo separado (no caso do dBASE, cada tabela é um arquivo. dbf). Drivers para outros bancos de dados ODBC, como Microsoft Access e o SQL Server, exigem que alguns critérios específicos ser atendidas antes de uma fonte de dados pode ser estabelecida. Por exemplo, ao usar o driver ODBC do SQL Server, você precisa estabelecer um computador SQL Server.  
  
##  <a name="_core_sqlconfigdatasource_example"></a> Exemplo SQLConfigDataSource  
 O exemplo a seguir usa o **:: SQLConfigDataSource** nova fonte de dados do Excel de chamada de função da API do ODBC para criar uma nova fonte de dados do Excel:  
  
```  
SQLConfigDataSource(NULL,ODBC_ADD_DSN, "Excel Files (*.xls)",   
                   "DSN=New Excel Data Source\0"   
                   "Description=New Excel Data Source\0"   
                   "FileType=Excel\0"   
                   "DataDirectory=C:\\EXCELDIR\0"   
                   "MaxScanRows=20\0");  
```  
  
 Observe que a fonte de dados é, na verdade, um diretório (C:\EXCELDIR); Esse diretório deve existir. O driver do Excel usa diretórios de suas fontes de dados e arquivos que as tabelas individuais (uma tabela por arquivo. xls).  
  
 Para obter mais informações sobre como criar tabelas, consulte [fonte de dados: Criando uma tabela em uma fonte de dados ODBC programaticamente](../../data/odbc/data-source-programmatically-creating-a-table-in-an-odbc-data-source.md).  
  
 As informações a seguir descreve os parâmetros que precisam ser passadas para o **:: SQLConfigDataSource** função da API do ODBC. Para usar **:: SQLConfigDataSource**, você deve incluir o arquivo de cabeçalho Odbcinst e usar a biblioteca de importação Odbcinst.lib. Além disso, ODBCCP32. dll deve estar no caminho no tempo de execução (ou Odbcinst de 16 bits).  
  
 Você pode criar um nome de fonte de dados ODBC usando o administrador ODBC ou um utilitário semelhante. No entanto, às vezes é desejável para criar um nome de fonte de dados diretamente do seu aplicativo para obter acesso sem exigir que o usuário executar um utilitário separado.  
  
 Administrador ODBC (normalmente instalado no painel de controle) cria uma nova fonte de dados colocando entradas no registro do Windows (ou, de 16 bits, no arquivo Odbc.ini). O Gerenciador de Driver ODBC consulta esse arquivo para obter as informações necessárias sobre a fonte de dados. É importante saber quais informações devem ser colocados no registro, porque você precisa fornecê-lo com a chamada para **:: SQLConfigDataSource**.  
  
 Embora essas informações podem ser gravadas diretamente para o registro sem usar **:: SQLConfigDataSource**, qualquer aplicativo que faz isso requer que a técnica atual que usa o Gerenciador de Driver para manter seus dados. Se uma revisão posterior ao Gerenciador de Driver ODBC implementa registro mantendo sobre fontes de dados de maneira diferente, qualquer aplicativo que usa essa técnica será interrompido. É aconselhável geralmente usa uma função de API quando é fornecida. Por exemplo, seu código é portátil de 16 bits para 32 bits se você usar o **:: SQLConfigDataSource** funcionar, pois a função grava corretamente o arquivo Odbc.ini ou no registro.  
  
##  <a name="_core_sqlconfigdatasource_parameters"></a> SQLConfigDataSource Parameters  
 A seguir explica os parâmetros de **:: SQLConfigDataSource** função. Muitas das informações é retirada da API do ODBC *referência do programador* fornecido com o Visual C++ versão 1.5 e posteriores.  
  
###  <a name="_core_function_prototype"></a> Protótipo de função  
  
```  
BOOL SQLConfigDataSource(HWND hwndParent,UINT fRequest, LPCSTR lpszDriver, LPCSTR lpszAttributes);  
```  
  
### <a name="remarks"></a>Comentários  
  
####  <a name="_core_parameters_and_usage"></a> Parâmetros e uso  
 *hwndParent*  
 A janela especificada como o proprietário de todas as caixas de diálogo que o Gerenciador de Driver ODBC ou o driver ODBC específico cria para obter informações adicionais do usuário sobre a nova fonte de dados. Se o `lpszAttributes` parâmetro não fornecer informações suficientes, uma caixa de diálogo é exibida. O *hwndParent* parâmetro pode ser **nulo**.  
  
 `lpszDriver`  
 A descrição do driver. Este é o nome apresentado para usuários em vez do nome do driver físico (DLL).  
  
 `lpszAttributes`  
 Lista de atributos no formato "keyname = value". Essas cadeias de caracteres são separadas por terminadores nulos com dois terminadores nulos consecutivos no final da lista. Esses atributos são principalmente específicos de driver entradas padrão, que vá para o registro para a nova fonte de dados. Uma chave importante não mencionados na referência da API do ODBC para essa função é "DSN" ("nome fonte de dados"), que especifica o nome da nova fonte de dados. O restante das entradas são específicas do driver para a nova fonte de dados. Geralmente não é necessário fornecer todas as entradas porque o driver pode solicitar que o usuário com caixas de diálogo para os novos valores. (Definido *hwndParent* para **nulo** para fazer com que isso.) Você talvez queira fornecer explicitamente os valores padrão para que o usuário não é solicitado.  
  
###### <a name="to-determine-the-description-of-a-driver-for-the-lpszdriver-parameter-using-odbc-administrator"></a>Para determinar a descrição de um driver para o parâmetro lpszDriver usando o administrador ODBC  
  
1.  Execute o administrador do ODBC.  
  
2.  Clique em **Adicionar**.  
  
 Isso fornece uma lista de drivers instalados e suas descrições. Use essa descrição como o `lpszDriver` parâmetro. Observe que você use a descrição inteira, como "Arquivos do Excel (*. xls)", incluindo a extensão de nome de arquivo e parênteses, se existirem na descrição.  
  
 Como alternativa, você pode examinar o registro (ou, para o arquivo Odbcinst.ini de 16 bits), que contém uma lista de todas as entradas de driver e descrições na chave do Registro "Drivers ODBC" (ou a seção [Drivers ODBC] Odbcinst.ini).  
  
 Uma maneira de localizar os keynames e valores para o `lpszAttributes` parâmetro é examinar o arquivo Odbc.ini para uma fonte de dados já configurado (talvez um que tenha sido configurado pelo administrador de ODBC).  
  
###### <a name="to-find-keynames-and-values-for-the-lpszattributes-parameter"></a>Para localizar keynames e valores para o parâmetro lpszAttributes  
  
1.  Execute o editor de registro do Windows (ou, de 16 bits, abra o arquivo Odbc.ini).  
  
2.  Localize as informações de fontes de dados ODBC usando um dos seguintes:  
  
    -   Para 32 bits, localizar a chave **HKEY_CURRENT_USER\Software\ODBC\ODBC. Fontes de dados INI\ODBC** no painel esquerdo.  
  
         O painel direito lista as entradas do formulário: "pub: REG_SZ:*<data source name>*", onde  *<data source name>*  é uma fonte de dados que já foi configurada com as configurações desejadas para o driver que você pretende Para usar. Selecione a fonte de dados, por exemplo, o SQL Server. Os itens a seguir a cadeia de caracteres "pub:" são, na ordem, o keyname e o valor para usar em seu `lpszAttributes` parâmetro.  
  
    -   Para 16 bits, localize a seção no arquivo Odbc.ini marcado por [*\<nome da fonte de dados >*].  
  
         As linhas desta linha a seguir têm o formato "keyname = value". Essas são exatamente as entradas para usar em seu `lpszAttributes` parâmetro.  
  
 Você também poderá examinar a documentação do driver específico que você pretende usar. Você pode encontrar informações úteis na Ajuda online para o driver, o que pode ser acessado usando o administrador ODBC. Esses arquivos de ajuda geralmente são colocados no diretório WINDOWS\SYSTEM para Windows NT, Windows 3.1 ou Windows 95.  
  
###### <a name="to-obtain-online-help-for-your-odbc-driver"></a>Para obter ajuda online para o driver ODBC  
  
1.  Execute o administrador do ODBC.  
  
2.  Clique em **Adicionar**.  
  
3.  Selecione o nome do driver.  
  
4.  Clique em **OK**.  
  
 Quando o administrador ODBC exibe as informações para criar uma nova fonte de dados para esse driver específico, clique em **ajuda**. Isso abre o arquivo de ajuda para esse driver específico, que geralmente contém informações importantes sobre o uso do driver.  
  
## <a name="see-also"></a>Consulte também  
 [Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)