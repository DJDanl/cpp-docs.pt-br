---
title: Usando acessadores dinâmicos
ms.date: 10/18/2018
helpviewer_keywords:
- accessors [C++], dynamic
- dynamic accessors
ms.assetid: e5d5bfa6-2b1d-49d0-8ced-914666422431
ms.openlocfilehash: eea1c6199fed5a4e6e331c1c76f34b96090b709a
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509411"
---
# <a name="using-dynamic-accessors"></a>Usando acessadores dinâmicos

Os acessadores dinâmicos permitem que você acesse uma fonte de dados quando você não tem nenhum conhecimento do esquema de banco (estrutura subjacente). A biblioteca de modelos de OLE DB fornece várias classes para ajudá-lo.

O exemplo [DynamicConsumer](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/DynamicConsumer) mostra como usar as classes de acessador dinâmico para obter informações de coluna e criar acessadores dinamicamente.

## <a name="using-cdynamicaccessor"></a>Usando CDynamicAccessor

O [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) permite que você acesse uma fonte de dados quando não tem nenhum conhecimento do esquema de banco de dado (a estrutura subjacente do banco de dados). `CDynamicAccessor` os métodos obtêm informações de coluna, como nomes de coluna, contagem e tipo de dados. Use essas informações de coluna para criar um acessador dinamicamente em tempo de execução. As informações de coluna são armazenadas em um buffer que é criado e gerenciado por essa classe. Obter dados do buffer usando o método [GetValue](./cdynamicaccessor-class.md#getvalue) .

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

[CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md) funciona como [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md), exceto de uma maneira importante. Enquanto o `CDynamicAccessor` solicita dados no formato nativo relatado pelo provedor, `CDynamicStringAccessor` o solicita que o provedor busque todos os dados acessados do armazenamento de dados como dados de cadeia de caracteres. O processo é especialmente útil para tarefas simples que não exigem o cálculo de valores no armazenamento de dados, como exibir ou imprimir o conteúdo do armazenamento de dados.

Use `CDynamicStringAccessor` métodos para obter informações de coluna. Use essas informações de coluna para criar um acessador dinamicamente em tempo de execução. As informações de coluna são armazenadas em um buffer criado e gerenciado por essa classe. Obter dados do buffer usando [CDynamicStringAccessor:: GetString](./cdynamicstringaccessor-class.md#getstring) ou armazená-los no buffer usando [CDynamicStringAccessor:: SetString](./cdynamicstringaccessor-class.md#setstring).

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

[CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md) é semelhante a [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md), exceto que `CDynamicParameterAccessor` Obtém informações de parâmetro a serem definidas chamando a interface [ICommandWithParameters](/sql/relational-databases/native-client-ole-db-interfaces/icommandwithparameters) . O provedor deve dar suporte ao `ICommandWithParameters` consumidor para usar essa classe.

As informações de parâmetro são armazenadas em um buffer criado e gerenciado por essa classe. Obter dados de parâmetro do buffer usando [CDynamicParameterAccessor:: GetParam](./cdynamicparameteraccessor-class.md#getparam) e [CDynamicParameterAccessor:: GetParamType](./cdynamicparameteraccessor-class.md#getparamtype).

Para obter um exemplo que demonstra como usar essa classe para executar um procedimento armazenado SQL Server e obter os valores de parâmetro de saída, consulte o código de exemplo [DynamicConsumer](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/DynamicConsumer) no repositório do [Microsoft VCSamples](https://github.com/Microsoft/VCSamples) no github.

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)<br/>
[Exemplo de DynamicConsumer](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/DynamicConsumer)
