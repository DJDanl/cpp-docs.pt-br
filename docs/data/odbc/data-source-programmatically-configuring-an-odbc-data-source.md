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
ms.openlocfilehash: 3d02a19d6c61e79fffd31b67ef1b8f7ea9007fcb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50677364"
---
# <a name="data-source-programmatically-configuring-an-odbc-data-source"></a>Fonte de dados: configurando programaticamente uma fonte de dados ODBC

Este tópico explica como você pode configurar nomes de fonte de dados de conectividade de banco de dados aberto (ODBC) por meio de programação. Isso oferece flexibilidade para acessar os dados sem forçar o usuário a usar explicitamente o administrador de ODBC ou outros programas para especificar os nomes de fontes de dados.

Normalmente, um usuário executa o administrador de ODBC para criar uma fonte de dados se o sistema de gerenciamento de banco de dados associado (DBMS) suportar esta operação.

Ao criar uma fonte de dados ODBC do Microsoft Access pelo administrador de ODBC, você terá duas opções: você pode selecionar um arquivo. mdb existente ou você pode criar um novo arquivo. mdb. Não há nenhuma maneira programático de criar o arquivo. mdb do seu aplicativo de ODBC do MFC. Portanto, se seu aplicativo requer que você coloque dados em uma fonte de dados do Microsoft Access (arquivo. mdb), você provavelmente deseja ter um arquivo. mdb vazio que você pode usar ou copiar sempre que for necessário.

No entanto, muitos DBMSs permitem a criação da fonte de dados via programação. Algumas fontes de dados mantêm uma especificação de diretório para bancos de dados. Ou seja, um diretório é a fonte de dados e cada tabela na fonte de dados é armazenada em um arquivo separado (no caso do dBASE, cada tabela é um arquivo. dbf). Drivers para outros bancos de dados ODBC, como Microsoft Access e o SQL Server, exigem que alguns critérios específicos ser atendida antes que uma fonte de dados pode ser estabelecida. Por exemplo, ao usar o driver ODBC do SQL Server, você precisa ter estabelecido um computador SQL Server.

##  <a name="_core_sqlconfigdatasource_example"></a> Exemplo de SQLConfigDataSource

O exemplo a seguir usa o `::SQLConfigDataSource` função de API ODBC para criar uma nova fonte de dados do Excel chamada nova fonte de dados do Excel:

```
SQLConfigDataSource(NULL,ODBC_ADD_DSN, "Excel Files (*.xls)",
                   "DSN=New Excel Data Source\0"
                   "Description=New Excel Data Source\0"
                   "FileType=Excel\0"
                   "DataDirectory=C:\\EXCELDIR\0"
                   "MaxScanRows=20\0");
```

Observe que a fonte de dados é, na verdade, um diretório (C:\EXCELDIR); Esse diretório deve existir. O driver do Excel usa diretórios como suas fontes de dados e arquivos como tabelas individuais (uma tabela por arquivo. xls).

Para obter mais informações sobre como criar tabelas, consulte [fonte de dados: Criando uma tabela em uma fonte de dados ODBC programaticamente](../../data/odbc/data-source-programmatically-creating-a-table-in-an-odbc-data-source.md).

As informações a seguir descreve os parâmetros que precisam ser passados para o `::SQLConfigDataSource` função ODBC API. Para usar `::SQLConfigDataSource`, você deve incluir o arquivo de cabeçalho Odbcinst e usar a biblioteca de importação Odbcinst. Além disso, Odbccp32.dll deve estar no caminho em tempo de execução (ou Odbcinst para 16 bits).

Você pode criar um nome de fonte de dados ODBC usando o administrador de ODBC ou um utilitário semelhante. No entanto, às vezes é desejável criar um nome de fonte de dados diretamente do seu aplicativo para obter acesso sem exigir que o usuário executar um utilitário separado.

Administrador de ODBC (normalmente instalado no painel de controle) cria uma nova fonte de dados colocando entradas no registro do Windows (ou, para 16 bits, no arquivo ODBC ini). O Gerenciador de Driver ODBC consulta esse arquivo para obter as informações necessárias sobre a fonte de dados. É importante saber qual informação precisa ser colocada no registro, porque você precisa fornecê-lo com a chamada para `::SQLConfigDataSource`.

Embora essas informações podem ser escritas diretamente para o registro sem usar `::SQLConfigDataSource`, qualquer aplicativo que faz isso é contar com a técnica atual que o Gerenciador de Driver usa para manter seus dados. Se uma revisão posterior ao Gerenciador de Driver ODBC implementa registro mantendo fontes de dados de maneira diferente, qualquer aplicativo que usa essa técnica será interrompido. É aconselhável usar uma função de API quando ele é fornecido. Por exemplo, seu código é portátil de 16 para 32 bits se você usar o `::SQLConfigDataSource` funcionar, porque a função grava corretamente no arquivo ODBC ini ou no registro.

##  <a name="_core_sqlconfigdatasource_parameters"></a> Parâmetros de SQLConfigDataSource

A seguir explica os parâmetros da `::SQLConfigDataSource` função. Muitas das informações é obtida da API do ODBC *referência do programador* fornecido com o Visual C++ versão 1.5 e posteriores.

###  <a name="_core_function_prototype"></a> Protótipo de função

```
BOOL SQLConfigDataSource(HWND hwndParent,UINT fRequest, LPCSTR lpszDriver, LPCSTR lpszAttributes);
```

### <a name="remarks"></a>Comentários

####  <a name="_core_parameters_and_usage"></a> Parâmetros e uso

*hwndParent*<br/>
A janela especificada como o proprietário de todas as caixas de diálogo que o Gerenciador de Driver ODBC ou o driver ODBC específico cria para obter informações adicionais do usuário sobre a nova fonte de dados. Se o *lpszAttributes* parâmetro fornece informações suficientes, será exibida uma caixa de diálogo. O *hwndParent* parâmetro pode ser NULL.

*lpszDriver*<br/>
A descrição do driver. Isso é o nome apresentado aos usuários, em vez do nome de driver físico (DLL).

*lpszAttributes*<br/>
Lista de atributos no formulário "keyname = value". Essas cadeias de caracteres são separadas por terminadores nulos com dois terminadores nulos consecutivos no final da lista. Esses atributos são principalmente padrão entradas específicas de driver, que são incluídos no registro para a nova fonte de dados. Uma chave importante que não é mencionada na referência da API do ODBC para essa função é "DSN" ("nome fonte de dados"), que especifica o nome da nova fonte de dados. O restante das entradas são específicas do driver para a nova fonte de dados. Muitas vezes não é necessário fornecer todas as entradas porque o driver pode avisar o usuário com caixas de diálogo para os novos valores. (Defina *hwndParent* como NULL para fazer com que isso.) Você talvez queira fornecer explicitamente valores padrão para que o usuário não seja solicitado.

#### <a name="to-determine-the-description-of-a-driver-for-the-lpszdriver-parameter-using-odbc-administrator"></a>Para determinar a descrição de um driver para o parâmetro lpszDriver usando o administrador ODBC

1. Execute o administrador de ODBC.

1. Clique em **Adicionar**.

Isso fornece uma lista dos drivers instalados e suas descrições. Use esta descrição como o *lpszDriver* parâmetro. Observe que você usa a descrição inteira, como "Arquivos do Excel (*. xls)", incluindo a extensão de nome de arquivo e os parênteses se eles existirem na descrição.

Como alternativa, você pode examinar o registro (ou, para 16 bits, o arquivo Odbcinst. ini), que contém uma lista de todas as entradas de driver e descrições na chave do Registro "Drivers ODBC" (ou a seção [ODBC Drivers] em Odbcinst. ini).

Uma maneira de localizar os nomes de chave e valores para o *lpszAttributes* parâmetro é examinar o arquivo ODBC ini para uma fonte de dados já configurada (talvez um que tenha sido configurado pelo administrador de ODBC).

#### <a name="to-find-keynames-and-values-for-the-lpszattributes-parameter"></a>Para localizar nomes de chave e valores para o parâmetro de lpszAttributes

1. Execute o editor de registro do Windows (ou, para 16 bits, abra o arquivo ini).

1. Localize as informações de fontes de dados ODBC usando um dos seguintes:

   - Para 32 bits, localize a chave **HKEY_CURRENT_USER\Software\ODBC\ODBC. Fontes de dados INI\ODBC** no painel esquerdo.

      O painel direito lista entradas no formato: "pub: REG_SZ:*<data source name>*", onde *<data source name>* é uma fonte de dados que já foi configurada com as configurações desejadas para o driver que você pretende Para usar. Selecione a fonte de dados que você deseja, por exemplo, o SQL Server. Os itens que seguem a cadeia de caracteres "pub:" são, por ordem, o keyname e o valor para usar em seu *lpszAttributes* parâmetro.

   - Para 16 bits, localize a seção no arquivo ini marcado por [*\<nome da fonte de dados >*].

      As linhas após esta linha estão no formato "keyname = value". Essas são exatamente as entradas para usar em seu *lpszAttributes* parâmetro.

Você também poderá examinar a documentação do driver específico que você pretende usar. Você pode encontrar informações úteis na Ajuda online para o driver, que pode ser acessada executando o administrador de ODBC. Esses arquivos de ajuda geralmente são colocados no diretório WINDOWS\SYSTEM para o Windows 95, Windows 3.1 ou Windows NT.

#### <a name="to-obtain-online-help-for-your-odbc-driver"></a>Para obter ajuda online para o driver ODBC

1. Execute o administrador de ODBC.

1. Clique em **Adicionar**.

1. Selecione o nome do driver.

1. Clique em **OK**.

Quando o administrador de ODBC exibir as informações para criar uma nova fonte de dados para o driver específico, clique em **ajudar**. Isso abre o arquivo de ajuda para o driver específico, que geralmente contém informações importantes sobre o uso do driver.

## <a name="see-also"></a>Consulte também

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)
