---
title: Usando acessadores dinâmicos | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- accessors [C++], dynamic
- dynamic accessors
ms.assetid: e5d5bfa6-2b1d-49d0-8ced-914666422431
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3a776043d8a65d0a037d17c1c2538a4606b4c9d1
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49808375"
---
# <a name="using-dynamic-accessors"></a>Usando acessadores dinâmicos

Acessadores dinâmicos permitem que você acesse uma fonte de dados quando você não tem nenhum conhecimento sobre o esquema de banco de dados (estrutura subjacente). A biblioteca de modelos OLE DB fornece várias classes para ajudá-lo.

O [DynamicConsumer](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/DynamicConsumer) exemplo mostra como usar as classes de acessador dinâmico para obter informações de coluna e criar dinamicamente os acessadores.

## <a name="using-cdynamicaccessor"></a>Usando CDynamicAccessor

[CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) permite que você acesse uma fonte de dados quando você não tem nenhum conhecimento sobre o esquema de banco de dados (estrutura de base do banco de dados). `CDynamicAccessor` métodos de obtém informações de coluna como nomes de coluna, a contagem e o tipo de dados. Você pode usar essas informações de coluna para criar um acessador dinamicamente em tempo de execução. As informações de coluna são armazenadas em um buffer que é criado e gerenciado por essa classe. Obter dados de buffer usando o [GetValue](../../data/oledb/cdynamicaccessor-getvalue.md) método.

## <a name="example"></a>Exemplo

```cpp
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

[CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md) funciona como [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md), exceto em um aspecto importante. Embora `CDynamicAccessor` solicita dados no formato nativo relatado pelo provedor, `CDynamicStringAccessor` solicita que o provedor de buscar todos os dados acessados do armazenamento de dados como dados de cadeia de caracteres. O processo é especialmente útil para tarefas simples que não exigem o cálculo dos valores no repositório de dados, como exibir ou imprimir o conteúdo do repositório de dados.

Use `CDynamicStringAccessor` métodos para obter informações de coluna. Você pode usar essas informações de coluna para criar um acessador dinamicamente em tempo de execução. As informações de coluna são armazenadas em um buffer criadas e gerenciadas por esta classe. Obter dados de buffer usando [cdynamicstringaccessor:: GetString](../../data/oledb/cdynamicstringaccessor-getstring.md) ou armazená-lo para o buffer usando [cdynamicstringaccessor:: Setstring](../../data/oledb/cdynamicstringaccessor-setstring.md).

## <a name="example"></a>Exemplo

```cpp
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

[CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md) é semelhante ao [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md), exceto pelo fato `CDynamicParameterAccessor` obtém informações de parâmetro a ser definido chamando o [ICommandWithParameters](/sql/relational-databases/native-client-ole-db-interfaces/icommandwithparameters) interface. O provedor deve oferecer suporte `ICommandWithParameters` para o consumidor usar essa classe.

As informações de parâmetro são armazenadas em um buffer criadas e gerenciadas por esta classe. Obter dados de parâmetro do buffer usando [cdynamicparameteraccessor:: Getparam](../../data/oledb/cdynamicparameteraccessor-getparam.md) e [cdynamicparameteraccessor:: Getparamtype](../../data/oledb/cdynamicparameteraccessor-getparamtype.md).

Para obter um exemplo que demonstra como usar essa classe para executar um procedimento armazenado do SQL Server e obter os valores de parâmetro de saída, consulte o [DynamicConsumer](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/DynamicConsumer) códigos de exemplo de [VCSamples Microsoft](https://github.com/Microsoft/VCSamples) repositório do GitHub.

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)<br/>
[Exemplo de DynamicConsumer](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/DynamicConsumer)  
