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
ms.openlocfilehash: 38f0f383256a05c983fb7e7d7a498e16881c7b78
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446950"
---
# <a name="data-source-programmatically-configuring-an-odbc-data-source"></a>Fonte de dados: configurando programaticamente uma fonte de dados ODBC

Este tópico explica como você pode configurar nomes de fonte de dados ODBC (Open Database Connectivity) programaticamente. Isso proporciona flexibilidade para acessar dados sem forçar o usuário a usar explicitamente o Administrador ODBC ou outros programas para especificar os nomes das fontes de dados.

Normalmente, um usuário executa o Administrador ODBC para criar uma fonte de dados se o DBMS (sistema de gerenciamento de banco de dados) associado der suporte a essa operação.

Ao criar uma fonte de dados ODBC do Microsoft Access por meio do Administrador ODBC, você recebe duas opções: você pode selecionar um arquivo. mdb existente ou pode criar um novo arquivo. mdb. Não há uma maneira programática de criar o arquivo. mdb de seu aplicativo ODBC do MFC. Portanto, se seu aplicativo exigir que você coloque dados em uma fonte de dados do Microsoft Access (arquivo. mdb), provavelmente você desejará ter um arquivo. mdb vazio que você pode usar ou copiar sempre que precisar.

No entanto, muitos DBMS permitem a criação programática da fonte de dados. Algumas fontes de dados mantêm uma especificação de diretório para bancos de dados. Ou seja, um diretório é a fonte de dados e cada tabela dentro da fonte de dados é armazenada em um arquivo separado (no caso do dBASE, cada tabela é um arquivo. dbf). Os drivers para outros bancos de dados ODBC, como o Microsoft Access e o SQL Server, exigem que alguns critérios específicos sejam satisfeitos antes que uma fonte de dados possa ser estabelecida. Por exemplo, ao usar o driver ODBC SQL Server, você precisa ter estabelecido um computador SQL Server.

##  <a name="_core_sqlconfigdatasource_example"></a>Exemplo de SQLConfigDataSource

O exemplo a seguir usa a função de API ODBC `::SQLConfigDataSource` para criar uma nova fonte de dados do Excel chamada nova fonte de dados do Excel:

```
SQLConfigDataSource(NULL,ODBC_ADD_DSN, "Excel Files (*.xls)",
                   "DSN=New Excel Data Source\0"
                   "Description=New Excel Data Source\0"
                   "FileType=Excel\0"
                   "DataDirectory=C:\\EXCELDIR\0"
                   "MaxScanRows=20\0");
```

Observe que a fonte de dados é, na verdade, um diretório (C:\EXCELDIR); Esse diretório deve existir. O driver do Excel usa diretórios como fontes de dados e arquivos como tabelas individuais (uma tabela por arquivo. xls).

Para obter mais informações sobre como criar tabelas, consulte [fonte de dados: Criando programaticamente uma tabela em uma fonte de dados ODBC](../../data/odbc/data-source-programmatically-creating-a-table-in-an-odbc-data-source.md).

As informações a seguir discutem os parâmetros que precisam ser passados para a `::SQLConfigDataSource` função da API ODBC. Para usar `::SQLConfigDataSource`, você deve incluir o arquivo de cabeçalho Odbcinst. h e usar a biblioteca de importação Odbcinst. lib. Além disso, Odbccp32. dll deve estar no caminho em tempo de execução (ou Odbcinst. dll para 16 bits).

Você pode criar um nome de fonte de dados ODBC usando o Administrador ODBC ou um utilitário semelhante. No entanto, às vezes, é desejável criar um nome de fonte de dados diretamente do seu aplicativo para obter acesso sem exigir que o usuário execute um utilitário separado.

O Administrador ODBC (normalmente instalado no painel de controle) cria uma nova fonte de dados colocando entradas no registro do Windows (ou, para 16 bits, no arquivo ODBC. ini). O Gerenciador de driver ODBC consulta esse arquivo para obter as informações necessárias sobre a fonte de dados. É importante saber quais informações precisam ser colocadas no registro porque você precisa fornecê-las com a chamada para `::SQLConfigDataSource`.

Embora essas informações possam ser gravadas diretamente no registro sem usar `::SQLConfigDataSource`, qualquer aplicativo que faça isso está contando com a técnica atual que o Gerenciador de driver usa para manter seus dados. Se uma revisão posterior ao Gerenciador de driver ODBC implementar o registro de manutenção de fontes de dados de forma diferente, qualquer aplicativo que use essa técnica será interrompido. Geralmente, é aconselhável usar uma função de API quando uma é fornecida. Por exemplo, seu código será portátil de 16 bits a 32 bits se você usar a função `::SQLConfigDataSource`, porque a função grava corretamente no arquivo ODBC. ini ou no registro.

##  <a name="_core_sqlconfigdatasource_parameters"></a>Parâmetros de SQLConfigDataSource

O seguinte explica os parâmetros da função `::SQLConfigDataSource`. Grande parte das informações é obtida da *referência do programador* de API do ODBC fornecida com C++ o Visual versão 1,5 e posterior.

###  <a name="_core_function_prototype"></a>Protótipo de função

```
BOOL SQLConfigDataSource(HWND hwndParent,UINT fRequest, LPCSTR lpszDriver, LPCSTR lpszAttributes);
```

### <a name="remarks"></a>Comentários

####  <a name="_core_parameters_and_usage"></a>Parâmetros e uso

*hwndParent*<br/>
A janela especificada como o proprietário de qualquer caixa de diálogo que o Gerenciador de driver ODBC ou o driver ODBC específico cria para obter informações adicionais do usuário sobre a nova fonte de dados. Se o parâmetro *lpszAttributes* não fornecer informações suficientes, será exibida uma caixa de diálogo. O parâmetro *hwndParent* pode ser nulo.

*lpszDriver*<br/>
A descrição do driver. Esse é o nome apresentado aos usuários em vez do nome do driver físico (a DLL).

*lpszAttributes*<br/>
Lista de atributos no formato "keyname = valor". Essas cadeias de caracteres são separadas por terminadores nulos com dois terminadores NULL consecutivos no final da lista. Esses atributos são basicamente entradas específicas de driver padrão, que entram no registro para a nova fonte de dados. Uma chave importante que não é mencionada na referência da API ODBC para essa função é "DSN" ("nome da fonte de dados"), que especifica o nome da nova fonte de dados. O restante das entradas é específico para o driver para a nova fonte de dados. Geralmente, não é necessário fornecer todas as entradas porque o driver pode solicitar ao usuário caixas de diálogo para os novos valores. (Defina *hwndParent* como nulo para causar isso.) Talvez você queira fornecer explicitamente valores padrão para que o usuário não seja solicitado.

#### <a name="to-determine-the-description-of-a-driver-for-the-lpszdriver-parameter-using-odbc-administrator"></a>Para determinar a descrição de um driver para o parâmetro lpszDriver usando o Administrador ODBC

1. Execute o Administrador ODBC.

1. Clique em **Adicionar**.

Isso fornece uma lista de drivers instalados e suas descrições. Use esta descrição como o parâmetro *lpszDriver* . Observe que você usa a descrição inteira, como "arquivos do Excel (*. xls)", incluindo a extensão de nome de arquivo e os parênteses, se existirem na descrição.

Como alternativa, você pode examinar o registro (ou, para 16 bits, o arquivo Odbcinst. ini), que contém uma lista de todas as entradas de driver e descrições na chave do registro "drivers ODBC" (ou na seção [drivers ODBC] em Odbcinst. ini).

Uma maneira de localizar o keynames e os valores para o parâmetro *lpszAttributes* é examinar o arquivo ODBC. ini para uma fonte de dados já configurada (talvez uma que tenha sido configurada pelo Administrador ODBC).

#### <a name="to-find-keynames-and-values-for-the-lpszattributes-parameter"></a>Para localizar keynames e valores para o parâmetro lpszAttributes

1. Execute o editor do registro do Windows (ou, para 16 bits, abra o arquivo ODBC. ini).

1. Localize as informações das fontes de dados ODBC usando uma das seguintes opções:

   - Para 32 bits, localize a chave **HKEY_CURRENT_USER \software\odbc\odbc. INI\ODBC fontes de dados** no painel esquerdo.

      O painel direito lista entradas do formulário: "pub: REG_SZ: *\<nome da fonte de dados >* ", em que *\<nome da fonte de dados >* é uma fonte de dados que já foi configurada com as configurações desejadas para o driver que você pretende usar. Selecione a fonte de dados desejada, por exemplo, SQL Server. Os itens após a cadeia de caracteres "pub:" são, em ordem, o keyname e o valor a serem usados no parâmetro *lpszAttributes* .

   - Para 16 bits, localize a seção no arquivo ODBC. ini marcada por [ *\<nome da fonte de dados >* ].

      As linhas após essa linha têm o formato "keyname = valor". Essas são exatamente as entradas a serem usadas no parâmetro *lpszAttributes* .

Talvez você também queira examinar a documentação do driver específico que pretende usar. Você pode encontrar informações úteis na ajuda online para o driver, que pode ser acessado executando o Administrador ODBC. Esses arquivos de ajuda geralmente são colocados no diretório WINDOWS\SYSTEM para Windows NT, Windows 3,1 ou Windows 95.

#### <a name="to-obtain-online-help-for-your-odbc-driver"></a>Para obter ajuda online para seu driver ODBC

1. Execute o Administrador ODBC.

1. Clique em **Adicionar**.

1. Selecione o nome do driver.

1. Clique em **OK**.

Quando o Administrador ODBC exibe as informações para criar uma nova fonte de dados para esse driver específico, clique em **ajuda**. Isso abre o arquivo de ajuda para esse driver específico, que geralmente contém informações importantes sobre o uso do driver.

## <a name="see-also"></a>Consulte também

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)
