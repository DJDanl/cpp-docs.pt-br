---
title: 'TN045: Suporte a MFC-banco de dados para Varchar-Varbinary longo'
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.data
helpviewer_keywords:
- TN045
- Varbinary data type
- Varchar data type
ms.assetid: cf572c35-5275-45b5-83df-5f0e36114f40
ms.openlocfilehash: 286ef403ec4bd51b035945f3ca268b59fee4d9d0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50567031"
---
# <a name="tn045-mfcdatabase-support-for-long-varcharvarbinary"></a>TN045: suporte a MFC/banco de dados para Varchar/Varbinary longo

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve como recuperar e enviar o ODBC **SQL_LONGVARCHAR** e **SQL_LONGVARBINARY** classes de banco de dados de tipos de dados usando o MFC.

## <a name="overview-of-long-varcharvarbinary-support"></a>Visão geral do suporte Varchar/Varbinary longo

O ODBC **SQL_LONG_VARCHAR** e **SQL_LONGBINARY** tipos de dados (chamados aqui como colunas de dados longos) podem armazenar enormes quantidades de dados. Há 3 modos você pode lidar com esses dados:

- Associe-o a um `CString` / `CByteArray`.

- Associe-o a um `CLongBinary`.

- Não associá-lo em todos os e recuperar e enviar o valor de dados long manualmente, independente das classes de banco de dados.

Cada um dos três métodos tem vantagens e desvantagens.

Não há suporte para colunas de dados Long para os parâmetros para uma consulta. Eles só têm suporte para outputColumns.

## <a name="binding-a-long-data-column-to-a-cstringcbytearray"></a>Associação de uma coluna de dados Long para um CString/CByteArray

Vantagens:

Essa abordagem é simple de entender e trabalhar com classes familiares. A estrutura fornece `CFormView` suporte para `CString` com `DDX_Text`. Você tem muita funcionalidade geral de cadeia de caracteres ou coleção com o `CString` e `CByteArray` classes e você pode controlar a quantidade de memória alocada localmente para armazenar o valor de dados. O framework mantém uma cópia antiga dos dados do campo durante `Edit` ou `AddNew` chamadas de função e o pode framework detectar automaticamente as alterações nos dados para você.

> [!NOTE]
>  Uma vez que `CString` foi projetado para trabalhar em dados de caractere, e `CByteArray` para trabalhar em dados binários, é recomendável que você coloque os dados de caractere (**SQL_LONGVARCHAR**) em `CString`e os dados binários ( **SQL_LONGVARBINARY**) em `CByteArray`.

A RFX funciona para o `CString` e `CByteArray` têm um argumento adicional que permite que você substituir o tamanho padrão de memória alocada para armazenar o valor recuperado para a coluna de dados. Observe o argumento nMaxLength nas declarações de função a seguir:

```
void AFXAPI RFX_Text(CFieldExchange* pFX,
    const char *szName,
    CString& value,
    int nMaxLength = 255,
    int nColumnType =
    SQL_VARCHAR);

void AFXAPI RFX_Binary(CFieldExchange* pFX,
    const char *szName,
    CByteArray& value,
    int nMaxLength = 255);
```

Se você recuperar uma coluna de dados longos em um `CString` ou `CByteArray`, o máximo retornado a quantidade de dados é, por padrão, 255 bytes. Nada além de isso será ignorado. Nesse caso, o framework gerará a exceção **AFX_SQL_ERROR_DATA_TRUNCATED**. Felizmente, você pode explicitamente aumentar nMaxLength para valores maiores, até **MAXINT**.

> [!NOTE]
>  O valor de nMaxLength usado pelo MFC para definir o buffer do local do `SQLBindColumn` função. Esse é o buffer local para o armazenamento de dados e realmente não afeta a quantidade de dados retornados pelo driver ODBC. `RFX_Text` e `RFX_Binary` apenas fazer uma chamada usando `SQLFetch` para recuperar os dados do banco de dados back-end. Cada driver ODBC tem uma limitação diferente na quantidade de dados, que elas podem retornar em uma única busca. Esse limite pode ser muito menor do que o valor definido em nMaxLength, em, nesse caso, a exceção **AFX_SQL_ERROR_DATA_TRUNCATED** será lançada. Sob essas circunstâncias, passar a usar `RFX_LongBinary` em vez de `RFX_Text` ou `RFX_Binary` para que todos os dados podem ser recuperados.

ClassWizard associará uma **SQL_LONGVARCHAR** para um `CString`, ou uma **SQL_LONGVARBINARY** para um `CByteArray` para você. Se você deseja alocar mais de 255 bytes na qual você recuperar sua coluna de dados longos, em seguida, forneça um valor explícito para nMaxLength.

Quando uma coluna de dados long é associada a um `CString` ou `CByteArray`, atualizando o campo funciona da mesma forma que quando ele é associado a um SQL _**VARCHAR** ou SQL _**VARBINARY**. Durante `Edit`, o valor de dados é armazenado em cache imediatamente e mais tarde quando comparados `Update` é chamado para detectar alterações nos dados de valor e defina o sujo e valores nulos para a coluna adequadamente.

## <a name="binding-a-long-data-column-to-a-clongbinary"></a>Associação de uma coluna de dados Long para um CLongBinary

Se a coluna de dados longos pode conter mais **MAXINT** bytes de dados, provavelmente convém recuperá-los em um `CLongBinary`.

Vantagens:

Isso recupera uma coluna de dados longo de todo, até que a memória disponível.

Desvantagens:

Os dados são mantidos na memória. Essa abordagem também é extremamente dispendiosa para grandes quantidades de dados. Você deve chamar `SetFieldDirty` para os dados associados membro para garantir que o campo é incluído em um `Update` operação.

Se você recuperar colunas de dados longos em um `CLongBinary`, as classes de banco de dados Verifique o tamanho total da coluna de dados longo e alocar um `HGLOBAL` segmento de memória grande o suficiente para conter o valor de inteiro de dados ele. As classes de banco de dados, em seguida, recupere o valor de inteiro de dados para o alocado `HGLOBAL`.

Se a fonte de dados não pode retornar o tamanho esperado da coluna de dados longo, o framework gerará a exceção **AFX_SQL_ERROR_SQL_NO_TOTAL**. Se a tentativa de alocar o `HGLOBAL` falhar, uma exceção de memória padrão é gerada.

ClassWizard associará uma **SQL_LONGVARCHAR** ou **SQL_LONGVARBINARY** para um `CLongBinary` para você. Selecione `CLongBinary` como o tipo de variável na caixa de diálogo Adicionar variável de membro. ClassWizard, em seguida, adicionará um `RFX_LongBinary` chamar seu `DoFieldExchange` chamar e incrementar o número total de campos associados.

Para atualizar os valores de coluna de dados longo, primeiro verifique se o alocados `HGLOBAL` é grande o suficiente para manter seus novos dados, chamando **:: GlobalSize** no *m_hData* membro do `CLongBinary`. Se ele for muito pequeno, liberar o `HGLOBAL` e alocar um tamanho apropriado. Em seguida, defina *m_dwDataLength* para refletir o novo tamanho.

Caso contrário, se *m_dwDataLength* é maior que o tamanho dos dados que você está substituindo, você pode liberar e realocar o `HGLOBAL`, ou deixá-lo alocada. Certifique-se indicar o número de bytes realmente usados no *m_dwDataLength*.

## <a name="how-updating-a-clongbinary-works"></a>Funciona como atualização de um CLongBinary

Não é necessário entender como atualizar um `CLongBinary` funciona, mas ele pode ser útil como um exemplo de como enviar valores de dados longos para uma fonte de dados, se você escolher esse método de terceiro, descrito abaixo.

> [!NOTE]
>  Para que um `CLongBinary` campo a ser incluído em uma atualização, você deve chamar explicitamente `SetFieldDirty` para o campo. Se você fizer qualquer alteração em um campo, incluindo a configuração de Null, você deve chamar `SetFieldDirty`. Você também deve chamar `SetFieldNull`, com o segundo parâmetro que está sendo **falso**, para marcar o campo como tendo um valor.

Ao atualizar uma `CLongBinary` campo, as classes de banco de dados usam do ODBC **DATA_AT_EXEC** mecanismo (consulte a documentação do ODBC no `SQLSetPos`do argumento rgbValue). Quando o framework prepara a instrução insert ou update, em vez de apontar para o `HGLOBAL` que contém os dados, o *endereço* da `CLongBinary` está definido como o *valor* da coluna em vez disso e o indicador de comprimento definido como **SQL_DATA_AT_EXEC**. Posteriormente, quando a instrução update é enviada para a fonte de dados `SQLExecDirect` retornarão **SQL_NEED_DATA**. Isso avisa que a estrutura que o valor do parâmetro para esta coluna é, na verdade, o endereço de um `CLongBinary`. A estrutura chama `SQLGetData` uma vez com um buffer pequeno, esperando que o driver para retornar o comprimento real dos dados. Se o driver retorna o comprimento real do objeto binário grande (BLOB), o MFC Realoca espaço quanto conforme necessário para buscar o BLOB. Se a fonte de dados retorna **SQL_NO_TOTAL**, indicando que não é possível determinar o tamanho do BLOB, a MFC criará blocos menores. O tamanho inicial padrão é 64K e blocos subsequentes serão dobra o tamanho; Por exemplo, a segunda será 128K, o terceiro é 256K e assim por diante. O tamanho inicial é configurável.

## <a name="not-binding-retrievingsending-data-directly-from-odbc-with-sqlgetdata"></a>Não Binding: Recuperando/enviar dados diretamente de ODBC com o SQLGetData

Com esse método você completamente ignorar as classes de banco de dados e lida com a coluna de dados longos.

Vantagens:

Você pode armazenar em cache os dados para disco, se necessário, ou decidir dinamicamente a quantidade de dados para recuperar.

Desvantagens:

Você não obtém a estrutura `Edit` ou `AddNew` suporte e você deve escrever código para executar a funcionalidade básica (`Delete` funciona, pois ele não é uma operação em nível de coluna).

Nesse caso, a coluna de dados long deve estar na lista de seleção do conjunto de registros, mas não deve ser associada a pelo framework. Uma forma de fazer isso é fornecer sua própria instrução SQL por meio `GetDefaultSQL` ou como o argumento lpszSQL `CRecordset`do `Open` de função e vincula a coluna adicional com uma chamada de função RFX_. O ODBC exige que campos não associados são exibidos à direita dos campos associados, para adicionar a coluna não associada ou colunas ao final da lista de seleção.

> [!NOTE]
>  Porque a coluna de dados long não está associada pela estrutura, as alterações não serão manipuladas com `CRecordset::Update` chamadas. Você deve criar e enviar o necessários do SQL **inserir** e **atualização** instruções por conta própria.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

