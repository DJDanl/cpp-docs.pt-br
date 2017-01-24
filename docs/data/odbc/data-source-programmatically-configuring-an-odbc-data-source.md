---
title: "Fonte de dados: configurando programaticamente uma fonte de dados ODBC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "SQLConfigDataSource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "configurando fontes de dados ODBC"
  - "Conexões ODBC, configurando"
  - "Fontes de dados ODBC, configurando"
  - "Exemplo de método SQLConfigDataSource"
ms.assetid: b8cabe9b-9e12-4d73-ae36-7cb12dee3213
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fonte de dados: configurando programaticamente uma fonte de dados ODBC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico explica como você pode configurar nomes de fonte de dados ODBC programaticamente.  Isso oferece flexibilidade para acessar dados sem forçar o usuário a usar explicitamente o Administrador de ODBC ou outros programas para especificar os nomes de fontes de dados.  
  
 Normalmente, um usuário executa o administrador de ODBC para criar uma fonte de dados se o sistema de gerenciamento associado de banco de dados \(DBMS\) suportar esta operação.  
  
 Ao criar uma fonte de dados ODBC do Microsoft Access pelo administrador de ODBC, você tem duas opções: você pode selecionar um arquivo .mdb existente ou criar um novo arquivo .mdb.  Não há nenhuma maneira programático de criar um .mdb do seu aplicativo ODBC do MFC.  Portanto, se seu aplicativo exigir que você coloque dados em uma fonte de dados do Microsoft Access \(arquivo .mdb\), provavelmente você vai querer ter um arquivo .mdb vazio que poderá usar ou copiar sempre que necessário.  
  
 No entanto, muitos DBMSs permitem a criação programática da fonte de dados.  Algumas fontes de dados mantêm uma especificação de diretório para bancos de dados.  OU seja, um diretório é a fonte de dados e cada tabela da fonte de dados é armazenada em um arquivo separado \(no caso do dBASE, cada tabela é um arquivo .dbf\).  Drivers para outros bancos de dados ODBC, como o Microsoft Access e SQL Server, exigem que alguns critérios específicos sejam satisfeitos para que uma fonte de dados possa ser estabelecida.  Por exemplo, ao usar o driver ODBC do SQL Server, você precisa ter estabelecido um computador SQL Server.  
  
##  <a name="_core_sqlconfigdatasource_example"></a> Exemplo de SQLConfigDataSource  
 O exemplo a seguir usa a função de API **::SQLConfigDataSource** ODBC para criar uma nova fonte de dados do Excel chamada Nova Fonte de Dados do Excel:  
  
```  
SQLConfigDataSource(NULL,ODBC_ADD_DSN, "Excel Files (*.xls)",   
                   "DSN=New Excel Data Source\0"   
                   "Description=New Excel Data Source\0"   
                   "FileType=Excel\0"   
                   "DataDirectory=C:\\EXCELDIR\0"   
                   "MaxScanRows=20\0");  
```  
  
 Observe que a fonte de dados é na verdade um diretório \(C:\\EXCELDIR\); este diretório deve existir.  O driver do Excel usa diretórios como suas fontes de dados e arquivos como tabelas individuais \(uma tabela por arquivo .xls\).  
  
 Para obter mais informações sobre como criar tabelas, consulte [Fonte de dados: Criar uma tabela de forma programática em uma fonte de dados ODBC](../../data/odbc/data-source-programmatically-creating-a-table-in-an-odbc-data-source.md).  
  
 As informações a seguir discute os parâmetros que precisam ser passados à função de API **::SQLConfigDataSource** ODBC.  Para usar **::SQLConfigDataSource**, você deve incluir o arquivo de cabeçalho Odbcinst.h e usar a biblioteca de importação Odbcinst.lib.  Além disso, o Odbccp32.dll deve estar no caminho em tempo de execução \(ou Odbcinst.dll para 16 bits\).  
  
 É possível criar um nome de fonte de dados ODBC usando o administrador de ODBC ou um utilitário semelhante.  No entanto, às vezes é desejável criar um nome para a fonte de dados diretamente do aplicativo para obter acesso sem exigir que o usuário execute um utilitário separado.  
  
 O Administrador de ODBC \(normalmente instalado no Painel de Controle\) cria uma nova fonte de dados colocando entradas no Registro do Windows \(ou, para o bit 16, no arquivo Odbc.ini\).  O Gerenciador de Driver ODBC consulta esse arquivo para obter as informações necessárias sobre a fonte de dados.  É importante saber qual informação precisa ser colocada no Registro, pois você precisa fornecê\-la com a chamada a **::SQLConfigDataSource**.  
  
 Embora essa informação possa ser escrita diretamente para o Registro sem usar **::SQLConfigDataSource**, qualquer aplicativo que faça isso está confiando na técnica atual que o Gerenciador de Driver usa para manter seus dados.  Se uma revisão posterior ao ODBC Driver Manager implementa o relatório mantendo fontes de dados de uma forma diferente, qualquer aplicativo que usar essa técnica é inválida.  Geralmente é aconselhável usar uma função da API, quando fornecida.  Por exemplo, seu código é portátil de 16 para 32 bits se você usa a função **::SQLConfigDataSource**, pois a função grava corretamente no arquivo Odbc.ini ou no Registro.  
  
##  <a name="_core_sqlconfigdatasource_parameters"></a> Parâmetros de SQLConfigDataSource  
 O exemplo a seguir explica os parâmetros da função **::SQLConfigDataSource**.  Muitas das informações são tiradas da *Referência do Programador* da API ODBC, fornecida com a versão 1.5 do Visual C\+\+ e posterior.  
  
###  <a name="_core_function_prototype"></a> Protótipo de função  
  
```  
BOOL SQLConfigDataSource(HWND hwndParent,UINT fRequest, LPCSTR lpszDriver, LPCSTR lpszAttributes);  
```  
  
### Comentários  
  
####  <a name="_core_parameters_and_usage"></a> Parâmetros e uso  
 *hwndParent*  
 A janela especificada como o proprietário de qualquer caixa de diálogo que o Gerenciador de Driver ODBC ou o driver ODBC específico cria para obter informações adicionais do usuário sobre a nova fonte de dados.  Se o parâmetro `lpszAttributes` não fornece informação suficiente, uma caixa de diálogo aparece.  O parâmetro *hwndParent* pode ser **NULL**.  
  
 `lpszDriver`  
 A descrição do driver.  Esse é o nome apresentado aos usuários em vez do nome físico de driver \(a DLL\).  
  
 `lpszAttributes`  
 Lista de atributos no formulário “keyname\=value”.  Essas cadeias de caracteres são separadas por terminadores nulos com dois terminadores nulos consecutivos no fim da lista.  Esses atributos são basicamente entradas específicas de driver padrão, que são incluídos no Registro para a nova fonte de dados.  Uma chave importante que não é mencionada na referência da API ODBC para essa função é um DSN \("nome de fonte de dados"\), que especifica o nome da nova fonte de dados.  O resto das entradas é específico do driver para a nova fonte de dados.  Muitas vezes não é necessário fornecer todas as entradas porque o driver pode avisar o usuário com caixas de diálogo para os novos valores. \(Defina *hwndParent* como **NULL** para causar isso.\) Você pode fornecer explicitamente valores padrão para que o usuário não seja solicitado.  
  
###### Para determinar a descrição de um driver para o parâmetro lpszDriver usando o Administrador de ODBC  
  
1.  Execute o Administrador de ODBC.  
  
2.  Clique em **Adicionar**.  
  
 Isso oferece a você uma lista de drivers instalados e suas descrições.  Use esta descrição como o parâmetro `lpszDriver`.  Observe que você usa a descrição inteira, como "Arquivos Excel \(\*.xls\)", incluindo a extensão de nome de arquivo e os parênteses se eles existirem na descrição.  
  
 Como alternativa, você pode examinar o Registro \(ou, para 16 bits, o arquivo Odbcinst.ini\), que contém uma lista de todas as entradas e descrições de driver sob a chave de Registro "Drivers ODBC" \(ou a seção \[ODBC Drivers\] em Odbcinst.ini\).  
  
 Uma maneira de localizar os nomes de tecla e os valores do parâmetro `lpszAttributes` é examinar o arquivo Odbc.ini em busca de uma fonte de dados já configurada \(talvez uma que tenha sido configurada pelo administrador de ODBC\).  
  
###### Para localizar nomes de chave e valores para o parâmetro de lpszAttributes  
  
1.  Execute o editor de Registro do Windows \(ou, para 16 bits, abra o arquivo Odbc.ini\).  
  
2.  Localize as informações de fontes de dados ODBC usando um destes procedimentos:  
  
    -   Para 32 bits, localize a chave **HKEY\_CURRENT\_USER\\Software\\ODBC\\ODBC.INI\\ODBC Data Sources** no painel esquerdo.  
  
         O painel direito lista entradas do formato: "pub: REG\_SZ:*\<nome da fonte de dados\>*", onde *\<nome da fonte de dados\>* é uma fonte de dados que já foi configurada com as definições desejadas para o driver que você pretende usar.  Selecione a fonte de dados desejada, por exemplo, o SQL Server.  Os itens que seguem a cadeia de caracteres "pub:" são, na ordem, o nome da chave e o valor a serem usados em seu parâmetro `lpszAttributes`.  
  
    -   Para 16 bits, localize a seção no arquivo Odbc.ini marcado por \[*\<nome da fonte de dados\>*\].  
  
         As linhas após esta linha estão no formato "nomedachave\=valor".  Essas são exatamente as entradas a serem usadas em seu parâmetro `lpszAttributes`.  
  
 Você também pode querer examinar a documentação do driver específico que será usado.  É possível localizar informações úteis na ajuda on\-line para o driver, que pode ser acessada executando o administrador de ODBC.  Esses arquivos da Ajuda são geralmente colocados no diretório WINDOWS\\SYSTEM para o Windows NT, o Windows 3.1 ou o Windows 95.  
  
###### Para obter ajuda on\-line para o driver ODBC  
  
1.  Execute o Administrador de ODBC.  
  
2.  Clique em **Adicionar**.  
  
3.  Selecione o nome do driver.  
  
4.  Clique em **OK**.  
  
 Quando o administrador de ODBC exibir as informações para criar uma nova fonte de dados para o driver específico, clique em **Ajuda**.  Isso abre o arquivo da Ajuda para o driver específico, que geralmente contém informações importantes a respeito do uso do driver.  
  
## Consulte também  
 [Fonte de dados \(ODBC\)](../../data/odbc/data-source-odbc.md)