---
title: "Usando acessadores dinâmicos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- accessors [C++], dynamic
- dynamic accessors
ms.assetid: e5d5bfa6-2b1d-49d0-8ced-914666422431
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a585605b4b89d55e136aa349e697e0c19c93974f
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="using-dynamic-accessors"></a>Usando acessadores dinâmicos
Acessadores dinâmicos permitem que você acesse uma fonte de dados quando você não possui conhecimento do esquema do banco de dados (estrutura subjacente). A biblioteca de modelos OLE DB fornece várias classes para ajudá-lo a fazer isso.  
  
 O [DynamicConsumer](http://msdn.microsoft.com/en-us/2ccc4c61-6749-4e83-aa81-00f8009c0dc3) exemplo mostra como usar as classes de acessador dinâmico para obter informações de coluna e criar dinamicamente os acessadores.  
  
## <a name="using-cdynamicaccessor"></a>Usando CDynamicAccessor  
 [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) permite que você acesse uma fonte de dados quando você não possui conhecimento do esquema do banco de dados (estrutura do banco de dados). `CDynamicAccessor` métodos de obter informações de coluna como nomes de coluna, contagem e tipo de dados. Você pode usar essas informações de coluna para criar um acessador dinamicamente em tempo de execução. As informações de coluna são armazenadas em um buffer que é criado e gerenciado por esta classe. Obter dados do buffer usando o [GetValue](../../data/oledb/cdynamicaccessor-getvalue.md) método.  
  
## <a name="example"></a>Exemplo  
  
### <a name="code"></a>Código  
  
```  
// Using_Dynamic_Accessors.cpp  
// compile with: /c /EHsc  
#include <stdio.h>  
#include <objbase.h>  
#include <atldbcli.h>  
  
int main(int argc, char* argv[] )  
{  
    HRESULT hr = CoInitialize(NULL );  
  
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
  
    hr = ss.Open(ds );  
    hr = rs.Open(ss, "Shippers" );  
  
    hr = rs.MoveFirst();  
    while(SUCCEEDED(hr ) && hr != DB_S_ENDOFROWSET )  
    {  
        for(size_t i = 1; i <= rs.GetColumnCount(); i++ )  
        {  
            DBTYPE type;  
            rs.GetColumnType(i, &type );  
            printf_s( "Column %d [%S] is of type %d\n",  
                      i, rs.GetColumnName(i ), type );   
  
            switch(type )  
            {  
                case DBTYPE_WSTR:  
                    printf_s( "value is %S\n",  
                              (WCHAR*)rs.GetValue(i ) );  
                break;  
                case DBTYPE_STR:  
                    printf_s( "value is %s\n",  
                              (CHAR*)rs.GetValue(i ) );  
                default:  
                    printf_s( "value is %d\n",  
                              *(long*)rs.GetValue(i ) );  
            }  
        }  
        hr = rs.MoveNext();  
    }  
  
    rs.Close();     
    ss.Close();  
    ds.Close();  
    CoUninitialize();  
  
    return 0;  
}  
```  
  
## <a name="using-cdynamicstringaccessor"></a>Usando CDynamicStringAccessor  
 [CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md) funciona como [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md), exceto em um aspecto importante. Enquanto `CDynamicAccessor` solicita os dados no formato nativo, o provedor relatado `CDynamicStringAccessor` solicita que o provedor de buscar todos os dados acessados a partir do repositório de dados como dados de cadeia de caracteres. Isso é especialmente útil para tarefas simples que não exigem o cálculo de valores no repositório de dados, como exibir ou imprimir o conteúdo do repositório de dados.  
  
 Use `CDynamicStringAccessor` métodos para obter informações de coluna. Você pode usar essas informações de coluna para criar um acessador dinamicamente em tempo de execução. As informações de coluna são armazenadas em um buffer criadas e gerenciadas por essa classe. Obter dados do buffer usando [cdynamicstringaccessor:: GetString](../../data/oledb/cdynamicstringaccessor-getstring.md) ou armazená-lo para o buffer usando [cdynamicstringaccessor:: Setstring](../../data/oledb/cdynamicstringaccessor-setstring.md).  
  
## <a name="example"></a>Exemplo  
  
### <a name="code"></a>Código  
  
```  
// Using_Dynamic_Accessors_b.cpp  
// compile with: /c /EHsc  
#include <stdio.h>  
#include <objbase.h>  
#include <atldbcli.h>  
  
int main(int argc, char* argv[] )  
{  
    HRESULT hr = CoInitialize(NULL );  
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
  
    hr = ss.Open(ds );  
    hr = rs.Open(ss, "Shippers" );  
  
    hr = rs.MoveFirst();  
    while(SUCCEEDED(hr ) && hr != DB_S_ENDOFROWSET )  
    {  
        for(size_t i = 1; i <= rs.GetColumnCount(); i++ )  
        {  
            printf_s( "column %d value is %s\n",   
                      i, rs.GetString(i ) );  
        }  
        hr = rs.MoveNext();  
    }  
  
    rs.Close();     
    ss.Close();  
    ds.Close();  
    CoUninitialize();  
  
   return 0;  
  
}  
```  
  
## <a name="using-cdynamicparameteraccessor"></a>Usando CDynamicParameterAccessor  
 [CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md) é semelhante a [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md), exceto que `CDynamicParameterAccessor` obtém informações de parâmetro a ser definido chamando o [ICommandWithParameters](https://msdn.microsoft.com/en-us/library/ms712937.aspx) interface. O provedor deve oferecer suporte `ICommandWithParameters` para o consumidor usar essa classe.  
  
 As informações de parâmetro são armazenadas em um buffer criadas e gerenciadas por essa classe. Obter dados de parâmetro do buffer usando [cdynamicparameteraccessor:: Getparam](../../data/oledb/cdynamicparameteraccessor-getparam.md) e [cdynamicparameteraccessor:: Getparamtype](../../data/oledb/cdynamicparameteraccessor-getparamtype.md).  
  
 Para obter um exemplo demonstram como usar essa classe para executar um procedimento armazenado do SQL Server e obter os valores de parâmetro de saída, consulte o artigo da Base de dados de Conhecimento Q058860, "como: executar um procedimento armazenado usando CDynamicParameterAccessor." Artigos da Base de dados de Conhecimento estão disponíveis na documentação do MSDN Library Visual Studio ou em [http://support.microsoft.com](http://support.microsoft.com/).  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)   
 [Exemplo de DynamicConsumer](http://msdn.microsoft.com/en-us/2ccc4c61-6749-4e83-aa81-00f8009c0dc3)