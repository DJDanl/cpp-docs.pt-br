---
title: Testando o provedor somente leitura simples
ms.date: 11/04/2016
helpviewer_keywords:
- testing, OLE DB providers
- testing providers
- OLE DB providers, calling
- OLE DB providers, testing
ms.assetid: e4aa30c1-391b-41f8-ac73-5270e46fd712
ms.openlocfilehash: a173e1466179dfb40a33d7bdb4a94eabdbf23cc0
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079054"
---
# <a name="testing-the-read-only-provider"></a>Testando o provedor somente leitura simples

Para testar um provedor, você precisa de um consumidor. Ele ajuda se o consumidor pode corresponder ao provedor. Os modelos de consumidor OLE DB são um wrapper fino em volta de OLE DB e correspondem aos objetos COM do provedor. Como a origem é enviada com os modelos de consumidor, é fácil depurar um provedor com eles. Os modelos de consumidor também são uma maneira muito pequena e rápida de desenvolver aplicativos de consumidor.

O exemplo neste tópico cria um aplicativo de assistente de aplicativo do MFC padrão para um consumidor de teste. O aplicativo de teste é uma caixa de diálogo simples com OLE DB código de modelo de consumidor adicionado.

## <a name="to-create-the-test-application"></a>Para criar o aplicativo de teste

1. No menu **Arquivo**, clique em **Novo** e clique em **Projeto**.

1. No painel **tipos de projeto** , selecione a **pasta instalada** > **Visual C++**  > **MFC/ATL** . No painel **modelos** , selecione **aplicativo MFC**.

1. Para o nome do projeto, insira *TestProv*e clique em **OK**.

   O assistente de **aplicativo do MFC** é exibido.

1. Na página **tipo de aplicativo** , selecione **baseado na caixa de diálogo**.

1. Na página **recursos avançados** , selecione **automação**e clique em **concluir**.

> [!NOTE]
> O aplicativo não exigirá suporte à automação se você adicionar `CoInitialize` no `CTestProvApp::InitInstance`.

Você pode exibir e editar a caixa de diálogo **TestProv** (IDD_TESTPROV_DIALOG) selecionando-a em **modo de exibição de recursos**. Coloque duas caixas de listagem, uma para cada cadeia de caracteres no conjunto de linhas, na caixa de diálogo. Desative a Propriedade Sort de ambas as caixas de listagem pressionando **Alt**+**Enter** quando uma caixa de listagem estiver selecionada e definindo a propriedade de **classificação** como **false**. Além disso, coloque um botão **executar** na caixa de diálogo para buscar o arquivo. A caixa de diálogo **TestProv** concluída deve ter duas caixas de listagem rotuladas "cadeia de caracteres 1" e "cadeia de caracteres 2", respectivamente; Ele também tem os botões **OK**, **Cancelar**e **executar** .

Abra o arquivo de cabeçalho da classe de caixa de diálogo (neste caso, TestProvDlg. h). Adicione o seguinte código ao arquivo de cabeçalho (fora de qualquer declaração de classe):

```cpp
////////////////////////////////////////////////////////////////////////
// TestProvDlg.h
#include <atldbcli.h>  

class CProvider
{
// Attributes
public:
   char   szField1[16];
   char   szField2[16];

   // Binding Maps
BEGIN_COLUMN_MAP(CProvider)
   COLUMN_ENTRY(1, szField1)
   COLUMN_ENTRY(2, szField2)
END_COLUMN_MAP()
};
```

O código representa um registro de usuário que define quais colunas estarão no conjunto de linhas. Quando o cliente chama `IAccessor::CreateAccessor`, ele usa essas entradas para especificar quais colunas vincular. Os modelos de consumidor OLE DB também permitem que você associe colunas dinamicamente. As macros COLUMN_ENTRY são a versão do lado do cliente do PROVIDER_COLUMN_ENTRY macros. As duas macros COLUMN_ENTRY especificam o ordinal, o tipo, o comprimento e o membro de dados para as duas cadeias de caracteres.

Adicione uma função de manipulador para o botão **executar** pressionando **Ctrl** e clicando duas vezes no botão **executar** . Coloque o seguinte código na função:

```cpp
///////////////////////////////////////////////////////////////////////
// TestProvDlg.cpp

void CTestProvDlg::OnRun()
{
   CCommand<CAccessor<CProvider>> table;
   CDataSource source;
   CSession session;

   if (source.Open("Custom.Custom.1", NULL) != S_OK)
      return;

   if (session.Open(source) != S_OK)
      return;

   if (table.Open(session, _T("c:\\samples\\myprov\\myData.txt")) != S_OK)
      return;

   while (table.MoveNext() == S_OK)
   {
      m_ctlString1.AddString(table.szField1);
      m_ctlString2.AddString(table.szField2);
   }
}
```

Todas as classes `CCommand`, `CDataSource`e `CSession` pertencem aos modelos de consumidor OLE DB. Cada classe imita um objeto COM no provedor. O objeto `CCommand` usa a classe `CProvider`, declarada no arquivo de cabeçalho, como um parâmetro de modelo. O parâmetro `CProvider` representa associações que você usa para acessar os dados do provedor.

As linhas para abrir cada uma das classes criam cada objeto COM no provedor. Para localizar o provedor, use o `ProgID` do provedor. Você pode obter a `ProgID` do registro do sistema ou procurando o arquivo. rgs personalizado (Abra o diretório do provedor e pesquise a chave de `ProgID`).

O arquivo MyData. txt está incluído no exemplo de `MyProv`. Para criar um arquivo próprio, use um editor e digite um número par de cadeias de caracteres, pressionando **Enter** entre cada cadeia. Altere o nome do caminho se você mover o arquivo.

Passe a cadeia de caracteres "c:\\\Samples\\\myprov\\\MyData.txt" na linha de `table.Open`. Se você entrar na chamada `Open`, verá que essa cadeia de caracteres é passada para o método `SetCommandText` no provedor. Observe que o método `ICommandText::Execute` usou essa cadeia de caracteres.

Para buscar os dados, chame `MoveNext` na tabela. `MoveNext` chama as funções `IRowset::GetNextRows`, `GetRowCount`e `GetData`. Quando não há mais linhas (ou seja, a posição atual no conjunto de linhas é maior que `GetRowCount`), o loop é encerrado.

Quando não há mais linhas, os provedores retornam DB_S_ENDOFROWSET. O valor de DB_S_ENDOFROWSET não é um erro. Você sempre deve verificar em relação a S_OK para cancelar um loop de busca de dados e não usar a macro com êxito.

Agora você deve ser capaz de criar e testar o programa.

## <a name="see-also"></a>Confira também

[Aprimorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)