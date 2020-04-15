---
title: 'Fonte de dados: configurando programaticamente uma fonte de dados ODBC'
ms.date: 11/04/2016
f1_keywords:
- SQLConfigDataSource
helpviewer_keywords:
- ODBC data sources, configuring
- SQLConfigDataSource method example
- ODBC connections, configuring
- configuring ODBC data sources
ms.assetid: b8cabe9b-9e12-4d73-ae36-7cb12dee3213
ms.openlocfilehash: ba0224d166795b34d636ace610265e115209e49c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358869"
---
# <a name="data-source-programmatically-configuring-an-odbc-data-source"></a>Fonte de dados: configurando programaticamente uma fonte de dados ODBC

Este tópico explica como você pode configurar nomes de fonte de dados de Open Database Connectivity (ODBC) de forma programática. Isso lhe dá flexibilidade para acessar dados sem forçar o usuário a usar explicitamente o administrador do ODBC ou outros programas para especificar os nomes das fontes de dados.

Normalmente, um usuário executa o Administrador ODBC para criar uma fonte de dados se o DBMS (Database Management System, sistema de gerenciamento de banco de dados associado) suportar essa operação.

Ao criar uma fonte de dados Microsoft Access ODBC através do Administrador ODBC, você tem duas opções: você pode selecionar um arquivo .mdb existente ou criar um novo arquivo .mdb. Não há nenhuma maneira programática de criar o arquivo .mdb a partir do seu aplicativo MFC ODBC. Portanto, se o seu aplicativo exigir que você coloque dados em uma fonte de dados do Microsoft Access (arquivo.mdb), você provavelmente deseja ter um arquivo .mdb vazio que você pode usar ou copiar sempre que precisar.

No entanto, muitos DBMSs permitem a criação de fontes de dados programáticas. Algumas fontes de dados mantêm uma especificação de diretório para bancos de dados. Ou seja, um diretório é a fonte de dados e cada tabela dentro da fonte de dados é armazenada em um arquivo separado (no caso do dBASE, cada tabela é um arquivo .dbf). Drivers para outros bancos de dados ODBC, como o Microsoft Access e o SQL Server, exigem que alguns critérios específicos sejam satisfeitos antes que uma fonte de dados possa ser estabelecida. Por exemplo, ao usar o driver SQL Server ODBC, você precisa ter estabelecido um computador SQL Server.

## <a name="sqlconfigdatasource-example"></a><a name="_core_sqlconfigdatasource_example"></a>Exemplo de fonte de sqlconfigDataSource

O exemplo a `::SQLConfigDataSource` seguir usa a função API do ODBC para criar uma nova fonte de dados do Excel chamada New Excel Data Source:

```
SQLConfigDataSource(NULL,ODBC_ADD_DSN, "Excel Files (*.xls)",
                   "DSN=New Excel Data Source\0"
                   "Description=New Excel Data Source\0"
                   "FileType=Excel\0"
                   "DataDirectory=C:\\EXCELDIR\0"
                   "MaxScanRows=20\0");
```

Observe que a fonte de dados é na verdade um diretório (C:\EXCELDIR); este diretório deve existir. O driver do Excel usa diretórios como suas fontes de dados e arquivos como tabelas individuais (uma tabela por arquivo .xls).

Para obter mais informações sobre a criação de tabelas, consulte [Fonte de dados: Programmaticamente Criando uma Tabela em uma Fonte de Dados ODBC](../../data/odbc/data-source-programmatically-creating-a-table-in-an-odbc-data-source.md).

As informações a seguir discutem os parâmetros `::SQLConfigDataSource` que precisam ser passados para a função API da ODBC. Para `::SQLConfigDataSource`usar, você deve incluir o arquivo de cabeçalho Odbcinst.h e usar a biblioteca de importação Odbcinst.lib. Além disso, Odbccp32.dll deve estar no caminho em tempo de execução (ou Odbcinst.dll por 16 bits).

Você pode criar um nome de origem de dados ODBC usando o Administrador ODBC ou um utilitário semelhante. No entanto, às vezes é desejável criar um nome de origem de dados diretamente do seu aplicativo para obter acesso sem exigir que o usuário execute um utilitário separado.

O administrador ODBC (normalmente instalado no Painel de Controle) cria uma nova fonte de dados colocando entradas no registro do Windows (ou, por 16 bits, no arquivo Odbc.ini). O Gerenciador de Driver oDBC consulta este arquivo para obter as informações necessárias sobre a fonte de dados. É importante saber quais informações precisam ser colocadas no registro, pois `::SQLConfigDataSource`você precisa fornecê-la com a chamada para .

Embora essas informações possam ser escritas `::SQLConfigDataSource`diretamente no registro sem usar , qualquer aplicativo que o faça está contando com a técnica atual que o Driver Manager usa para manter seus dados. Se uma revisão posterior ao ODBC Driver Manager implementar a manutenção de registros sobre fontes de dados de uma maneira diferente, qualquer aplicativo que use essa técnica será quebrado. Geralmente é aconselhável usar uma função de API quando uma é fornecida. Por exemplo, seu código é portátil de 16 bits a 32 bits se você usar a `::SQLConfigDataSource` função, porque a função grava corretamente para o arquivo Odbc.ini ou para o registro.

## <a name="sqlconfigdatasource-parameters"></a><a name="_core_sqlconfigdatasource_parameters"></a>SQLConfigDataSource Parâmetros

O seguinte explica os `::SQLConfigDataSource` parâmetros da função. Grande parte das informações é retirada da *Referência do Programador* Depi API da ODBC fornecida com visual C++ versão 1.5 e posterior.

### <a name="function-prototype"></a><a name="_core_function_prototype"></a>Protótipo de função

```
BOOL SQLConfigDataSource(HWND hwndParent,UINT fRequest, LPCSTR lpszDriver, LPCSTR lpszAttributes);
```

### <a name="remarks"></a>Comentários

#### <a name="parameters-and-usage"></a><a name="_core_parameters_and_usage"></a>Parâmetros e Uso

*Hwndparent*<br/>
A janela especificada como a dona de qualquer caixa de diálogo que o Gerenciador de Driver ODBC ou o driver ODBC específico cria para obter informações adicionais do usuário sobre a nova fonte de dados. Se o parâmetro *lpszAttributes* não fornecer informações suficientes, uma caixa de diálogo será exibida. O parâmetro *hwndParent* pode ser NULO.

*Lpszdriver*<br/>
A descrição do motorista. Este é o nome apresentado aos usuários e não o nome do driver físico (o DLL).

*Lpszattributes*<br/>
Lista de atributos no formulário "keyname=value". Essas seqüências são separadas por exterminadores nulos com dois exterminadores nulos consecutivos no final da lista. Esses atributos são principalmente entradas específicas de driver padrão, que vão para o registro da nova fonte de dados. Uma chave importante que não é mencionada na referência da API ODBC para esta função é "DSN" ("nome de origem de dados"), que especifica o nome da nova fonte de dados. O restante das entradas são específicos para o driver para a nova fonte de dados. Muitas vezes não é necessário fornecer todas as entradas porque o driver pode solicitar ao usuário caixas de diálogo para os novos valores. (Defina *hwndParent* para NULL para causar isso.) Você pode querer fornecer explicitamente valores padrão para que o usuário não seja solicitado.

#### <a name="to-determine-the-description-of-a-driver-for-the-lpszdriver-parameter-using-odbc-administrator"></a>Para determinar a descrição de um driver para o parâmetro lpszDriver usando o administrador ODBC

1. Execute o administrador ODBC.

1. Clique em **Adicionar**.

Isso lhe dá uma lista de drivers instalados e suas descrições. Use esta descrição como parâmetro *lpszDriver.* Observe que você usa toda a descrição, como "Arquivos Excel (*.xls)", incluindo a extensão do nome do arquivo e parênteses se eles existirem na descrição.

Como alternativa, você pode examinar o registro (ou, por 16 bits, o arquivo Odbcinst.ini), que contém uma lista de todas as entradas e descrições do driver sob a chave de registro "Drivers ODBC" (ou a seção [Drivers ODBC] em Odbcinst.ini).

Uma maneira de encontrar os nomes-chave e valores para o parâmetro *lpszAttributes* é examinar o arquivo Odbc.ini para uma fonte de dados já configurada (talvez uma que tenha sido configurada pelo administrador do ODBC).

#### <a name="to-find-keynames-and-values-for-the-lpszattributes-parameter"></a>Para encontrar nomes de chave e valores para o parâmetro lpszAttributes

1. Execute o editor de registro do Windows (ou, por 16 bits, abra o arquivo Odbc.ini).

1. Encontre as informações das fontes de dados da ODBC usando uma das seguintes informações:

   - Para 32 bits, encontre a chave **HKEY_CURRENT_USER\Software\ODBC\ODBC. Ini\ODBC Fontes de dados** no painel esquerdo.

      O painel direito lista as entradas do formulário: "pub: REG_SZ:*\<nome de origem de dados>*", onde * \<o nome de fonte de dados>* é uma fonte de dados que já foi configurada com as configurações desejadas para o driver que você pretende usar. Selecione a fonte de dados desejada, por exemplo, SQL Server. Os itens seguindo a string "pub:" são, em ordem, o nome-chave e o valor a serem usados no parâmetro *lpszAttributes.*

   - Por 16 bits, encontre a seção no arquivo*\< *Odbc.ini marcada pelo [ nome de origem dos dados>].

      As linhas seguintes a esta linha são do formulário "keyname=value". Estas são exatamente as entradas a serem usados em seu parâmetro *lpszAttributes.*

Você também pode querer examinar a documentação para o driver específico que você vai usar. Você pode encontrar informações úteis na Ajuda on-line para o driver, que você pode acessar executando o Administrador ODBC. Esses arquivos de Ajuda geralmente são colocados no diretório WINDOWS\SYSTEM para Windows NT, Windows 3.1 ou Windows 95.

#### <a name="to-obtain-online-help-for-your-odbc-driver"></a>Para obter ajuda on-line para o driver ODBC

1. Execute o administrador ODBC.

1. Clique em **Adicionar**.

1. Selecione o nome do driver.

1. Clique em **OK**.

Quando o administrador do ODBC exibir as informações para criar uma nova fonte de dados para esse driver em particular, clique **em Ajuda**. Isso abre o arquivo Ajuda para esse driver em particular, que geralmente contém informações importantes sobre o uso do driver.

## <a name="see-also"></a>Confira também

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)
