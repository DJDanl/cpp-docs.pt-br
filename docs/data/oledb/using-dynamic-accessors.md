---
title: "Usando acessadores din&#226;micos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "acessadores [C++], dynamic"
  - "acessadores dinâmicos"
ms.assetid: e5d5bfa6-2b1d-49d0-8ced-914666422431
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando acessadores din&#226;micos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os acessadores dinâmicas permitem que você acessar uma fonte de dados quando você não tem conhecimento do esquema de base de dados \(estrutura subjacente\).  Os modelos que OLE DB a biblioteca fornece várias classes para ajudar você faz isso.  
  
 O exemplo de [DynamicConsumer](http://msdn.microsoft.com/pt-br/2ccc4c61-6749-4e83-aa81-00f8009c0dc3) mostra como usar as classes dinâmicas do acessador para obter informações sobre colunas e para criar acessadores dinamicamente.  
  
## Usando CDynamicAccessor  
 [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) permite acessar uma fonte de dados quando você não tem conhecimento do esquema de base de dados \(a estrutura subjacente do base de dados\).  os métodos de`CDynamicAccessor` obtêm informações de coluna como nomes de coluna, count, e tipo de dados.  Você usa essas informações de coluna para criar dinamicamente em tempo de execução um acessador.  As informações de coluna é armazenada em um buffer que é criada e gerenciada por essa classe.  Obtenha dados do buffer usando o método de [GetValue](../../data/oledb/cdynamicaccessor-getvalue.md) .  
  
## Exemplo  
  
### Código  
  
```  
// Using_Dynamic_Accessors.cpp  
// compile with: /c /EHsc  
#include <stdio.h>  
#include <objbase.h>  
#include <atldbcli.h>  
  
int main( int argc, char* argv[] )  
{  
    HRESULT hr = CoInitialize( NULL );  
  
    CDataSource ds;  
    CSession ss;  
  
    CTable<CDynamicAccessor> rs;  
  
    // The following is an example initialization string:  
    hr = ds.OpenFromInitializationString(L"Provider=SQLOLEDB.1;"  
      L"Integrated Security=SSPI;Persist Security Info=False;"  
      L"Initial Catalog=Loginname;Data Source=your_data_source;"  
      L"Use Procedure for Prepare=1;Auto Translate=True;"  
      L"Packet Size=4096;Workstation ID=LOGINNAME01;"  
      L"Use Encryption for Data=False;"  
      L"Tag with column collation when possible=False");  
  
    hr = ss.Open( ds );  
    hr = rs.Open( ss, "Shippers" );  
  
    hr = rs.MoveFirst( );  
    while( SUCCEEDED( hr ) && hr != DB_S_ENDOFROWSET )  
    {  
        for( size_t i = 1; i <= rs.GetColumnCount( ); i++ )  
        {  
            DBTYPE type;  
            rs.GetColumnType( i, &type );  
            printf_s( "Column %d [%S] is of type %d\n",  
                      i, rs.GetColumnName( i ), type );   
  
            switch( type )  
            {  
                case DBTYPE_WSTR:  
                    printf_s( "value is %S\n",  
                              (WCHAR*)rs.GetValue( i ) );  
                break;  
                case DBTYPE_STR:  
                    printf_s( "value is %s\n",  
                              (CHAR*)rs.GetValue( i ) );  
                default:  
                    printf_s( "value is %d\n",  
                              *(long*)rs.GetValue( i ) );  
            }  
        }  
        hr = rs.MoveNext( );  
    }  
  
    rs.Close();     
    ss.Close();  
    ds.Close();  
    CoUninitialize();  
  
    return 0;  
}  
```  
  
## Usando CDynamicStringAccessor  
 [CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md) funciona como [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md), exceto em uma forma importante.  Quando `CDynamicAccessor` solicitar dados em formato nativo relatado pelo provedor, `CDynamicStringAccessor` solicita que o modo do provedor todos os dados tiverem acessado do repositório de dados como dados de cadeia de caracteres.  Isso é especialmente útil para as tarefas simples que não exigem o cálculo de valores no repositório de dados, como exibir ou imprimir o conteúdo do repositório de dados.  
  
 Use os métodos de `CDynamicStringAccessor` para obter informações de coluna.  Você usa essas informações de coluna para criar dinamicamente em tempo de execução um acessador.  As informações de coluna é armazenada em um buffer criada e gerenciada por essa classe.  Obtenha dados do buffer usando [CDynamicStringAccessor::GetString](../Topic/CDynamicStringAccessor::GetString.md) ou armazená\-los no buffer usando [CDynamicStringAccessor::SetString](../../data/oledb/cdynamicstringaccessor-setstring.md).  
  
## Exemplo  
  
### Código  
  
```  
// Using_Dynamic_Accessors_b.cpp  
// compile with: /c /EHsc  
#include <stdio.h>  
#include <objbase.h>  
#include <atldbcli.h>  
  
int main( int argc, char* argv[] )  
{  
    HRESULT hr = CoInitialize( NULL );  
    if (hr != S_OK)  
    {  
        exit (-1);  
    }  
  
    CDataSource ds;  
    CSession ss;  
  
    CTable<CDynamicStringAccessor> rs;  
  
    // The following is an example initialization string:  
    hr = ds.OpenFromInitializationString(L"Provider=SQLOLEDB.1;"  
      L"Integrated Security=SSPI;Persist Security Info=False;"  
      L"Initial Catalog=Loginname;Data Source=your_data_source;"  
      L"Use Procedure for Prepare=1;Auto Translate=True;"  
      L"Packet Size=4096;Workstation ID=LOGINNAME01;"  
      L"Use Encryption for Data=False;"  
      L"Tag with column collation when possible=False");  
  
    hr = ss.Open( ds );  
    hr = rs.Open( ss, "Shippers" );  
  
    hr = rs.MoveFirst( );  
    while( SUCCEEDED( hr ) && hr != DB_S_ENDOFROWSET )  
    {  
        for( size_t i = 1; i <= rs.GetColumnCount( ); i++ )  
        {  
            printf_s( "column %d value is %s\n",   
                      i, rs.GetString( i ) );  
        }  
        hr = rs.MoveNext( );  
    }  
  
    rs.Close();     
    ss.Close();  
    ds.Close();  
    CoUninitialize();  
  
   return 0;  
  
}  
```  
  
## Usando CDynamicParameterAccessor  
 [CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md) é semelhante a [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md), exceto que `CDynamicParameterAccessor` obtém as informações de parâmetro a ser definida chamando a interface de [ICommandWithParameters](https://msdn.microsoft.com/en-us/library/ms712937.aspx) .  O provedor deve oferecer suporte `ICommandWithParameters` para o consumidor use essa classe.  
  
 Informações de parâmetro é armazenada em um buffer criada e gerenciada por essa classe.  Obtenha dados do parâmetro do buffer usando [CDynamicParameterAccessor::GetParam](../Topic/CDynamicParameterAccessor::GetParam.md) e [CDynamicParameterAccessor::GetParamType](../../data/oledb/cdynamicparameteraccessor-getparamtype.md).  
  
 Para obter um exemplo que demonstra como usar essa classe para executar um procedimento armazenado do SQL Server e para obter os valores de parâmetro de saída, consulte o artigo da Base de Dados de Conhecimento Q058860, “HOWTO: Execute o procedimento armazenado usando CDynamicParameterAccessor”. Os artigos da Base de Dados de Conhecimento estão disponíveis na documentação do MSDN library o Visual Studio ou em [http:\/\/support.microsoft.com](http://support.microsoft.com/).  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)   
 [DynamicConsumer Sample](http://msdn.microsoft.com/pt-br/2ccc4c61-6749-4e83-aa81-00f8009c0dc3)