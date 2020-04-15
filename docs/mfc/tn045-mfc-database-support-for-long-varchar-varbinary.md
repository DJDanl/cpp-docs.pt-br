---
title: 'TN045: Suporte mfc-banco de dados para Varchar-Varbinary longo'
ms.date: 11/04/2016
helpviewer_keywords:
- TN045
- Varbinary data type
- Varchar data type
ms.assetid: cf572c35-5275-45b5-83df-5f0e36114f40
ms.openlocfilehash: f67d159fb600dcacd8eedd40e672edf18bddee9a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365505"
---
# <a name="tn045-mfcdatabase-support-for-long-varcharvarbinary"></a>TN045: suporte a MFC/banco de dados para Varchar/Varbinary longo

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota descreve como recuperar e enviar os tipos **de dados SQL_LONGVARCHAR** e **SQL_LONGVARBINARY** do ODBC usando as classes de banco de dados MFC.

## <a name="overview-of-long-varcharvarbinary-support"></a>Visão geral do suporte ao Varchar/Varbinary longo

Os SQL_LONG_VARCHAR **e** **SQL_LONGBINARY** tipos de dados da ODBC (referidos aqui como colunas de dados longas) podem conter enormes quantidades de dados. Existem 3 maneiras de lidar com esses dados:

- Amarre-o `CString` / `CByteArray`a um.

- Amarre-o `CLongBinary`a um.

- Não vinculá-lo em tudo e recuperar e enviar o longo valor de dados manualmente, independente das classes de banco de dados.

Cada um dos três métodos tem vantagens e desvantagens.

Colunas de dados longas não são suportadas para parâmetros de uma consulta. Eles são suportados apenas para outputColumns.

## <a name="binding-a-long-data-column-to-a-cstringcbytearray"></a>Vinculando uma coluna de dados longos a um CString/CByteArray

Vantagens:

Esta abordagem é simples de entender, e você trabalha com classes familiares. A estrutura `CFormView` fornece `CString` `DDX_Text`suporte para. Você tem muitas funcionalidades gerais de `CString` `CByteArray` seqüência ou coleta com as classes e, e você pode controlar a quantidade de memória alocada localmente para manter o valor dos dados. O framework mantém uma cópia `Edit` `AddNew` antiga de dados de campo durante chamadas de função ou de função, e a estrutura pode detectar automaticamente alterações nos dados para você.

> [!NOTE]
> Uma `CString` vez que é projetado `CByteArray` para trabalhar em dados de caracteres, e para trabalhar em `CString`dados binários, recomenda-se que você coloque os dados de caracteres **(SQL_LONGVARCHAR)** em , e os dados binários **(SQL_LONGVARBINARY)** em `CByteArray`.

O RFX funciona `CString` `CByteArray` e tem um argumento adicional que permite substituir o tamanho padrão da memória alocada para manter o valor recuperado para a coluna de dados. Observe o argumento nMaxLength nas seguintes declarações de função:

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

Se você recuperar uma coluna `CString` `CByteArray`de dados longos em um ou , a quantidade máxima devolvida de dados é, por padrão, 255 bytes. Qualquer coisa além disso é ignorada. Neste caso, o quadro abrirá a exceção **AFX_SQL_ERROR_DATA_TRUNCATED**. Felizmente, você pode aumentar explicitamente nMaxLength para valores maiores, até **MAXINT**.

> [!NOTE]
> O valor de nMaxLength é usado pelo MFC `SQLBindColumn` para definir o buffer local da função. Este é o buffer local para armazenamento dos dados e não afeta de fato a quantidade de dados devolvidos pelo driver ODBC. `RFX_Text`e `RFX_Binary` faça apenas `SQLFetch` uma chamada usando para recuperar os dados do banco de dados back-end. Cada driver ODBC tem uma limitação diferente na quantidade de dados que eles podem retornar em uma única busca. Esse limite pode ser muito menor do que o valor definido em nMaxLength, nesse caso a exceção **AFX_SQL_ERROR_DATA_TRUNCATED** será lançada. Nestas circunstâncias, mude `RFX_LongBinary` para `RFX_Text` `RFX_Binary` usar em vez de ou para que todos os dados possam ser recuperados.

ClassWizard vinculará **SQL_LONGVARCHAR** um `CString`SQL_LONGVARCHAR a um `CByteArray` , ou um **SQL_LONGVARBINARY** a um para você. Se você quiser alocar mais de 255 bytes nos quais você recupera sua coluna de dados longos, você pode fornecer um valor explícito para nMaxLength.

Quando uma coluna de dados `CString` `CByteArray`longos está vinculada a um ou , a atualização do campo funciona da mesma forma que quando está vinculado a um SQL_**VARCHAR** ou SQL_**VARBINARY**. Durante `Edit`, o valor dos dados é `Update` armazenado em cache e posteriormente comparado quando é chamado para detectar alterações no valor dos dados e definir os valores Sujo e Nulo para a coluna apropriadamente.

## <a name="binding-a-long-data-column-to-a-clongbinary"></a>Vinculando uma coluna de dados longos a um CLongBinary

Se sua longa coluna de dados pode conter mais bytes **MAXINT** `CLongBinary`de dados, você provavelmente deve considerar recuperá-los em um .

Vantagens:

Isso recupera uma coluna de dados longa inteira, até a memória disponível.

As desvantagens:

Os dados estão guardados na memória. Esta abordagem também é proibitivamente cara para grandes quantidades de dados. Você deve `SetFieldDirty` chamar o membro de dados vinculado `Update` para garantir que o campo seja incluído em uma operação.

Se você recuperar colunas `CLongBinary`de dados longas em um, as classes de banco `HGLOBAL` de dados verificarão o tamanho total da coluna de dados longos e, em seguida, alocarão um segmento de memória grande o suficiente para mantê-lo com todo o valor dos dados. As classes de banco de dados então `HGLOBAL`recuperam todo o valor dos dados no alocado .

Se a fonte de dados não puder retornar o tamanho esperado da coluna de dados longos, o framework lançará a exceção **AFX_SQL_ERROR_SQL_NO_TOTAL**. Se a tentativa `HGLOBAL` de alocar o falhar, uma exceção de memória padrão será lançada.

ClassWizard vinculará um **SQL_LONGVARCHAR** `CLongBinary` ou **SQL_LONGVARBINARY** a um para você. Selecione `CLongBinary` como o tipo de variável na caixa de diálogo Adicionar variável de membro. O ClassWizard adicionará `RFX_LongBinary` uma `DoFieldExchange` chamada à sua chamada e incrementará o número total de campos vinculados.

Para atualizar os valores da coluna `HGLOBAL` de dados longos, primeiro certifique-se de que o `CLongBinary`alocado é grande o suficiente para manter seus novos dados ligando para **::GlobalSize** no *m_hData* membro do . Se for muito pequeno, `HGLOBAL` solte o e aloque o tamanho apropriado. Em seguida, definir *m_dwDataLength* para refletir o novo tamanho.

Caso contrário, se *m_dwDataLength* for maior do que o tamanho dos dados que `HGLOBAL`você está substituindo, você pode liberar e realocar o , ou deixá-lo alocado. Certifique-se de indicar o número de bytes realmente usados em *m_dwDataLength*.

## <a name="how-updating-a-clongbinary-works"></a>Como funciona a atualização de um CLongBinary

Não é necessário entender como `CLongBinary` a atualização de um funciona, mas pode ser útil como exemplo de como enviar valores de dados longos para uma fonte de dados, se você escolher este terceiro método, descrito abaixo.

> [!NOTE]
> Para que `CLongBinary` um campo seja incluído em uma atualização, você deve explicitamente chamar `SetFieldDirty` para o campo. Se você fizer qualquer alteração em um campo, `SetFieldDirty`incluindo defini-lo Nulo, você deve chamar . Você também `SetFieldNull`deve chamar , com o segundo parâmetro sendo **FALSO**, para marcar o campo como tendo um valor.

Ao atualizar `CLongBinary` um campo, as classes de banco de dados usam `SQLSetPos`o mecanismo de **DATA_AT_EXEC** do ODBC (consulte a documentação do ODBC no argumento 'rgbValue]). Quando o framework prepara a instrução de `HGLOBAL` inserção ou atualização, `CLongBinary` em vez de apontar para o contendo os dados, o *endereço* do é definido como o *valor* da coluna e o indicador de comprimento definido como **SQL_DATA_AT_EXEC**. Posteriormente, quando a declaração de `SQLExecDirect` atualização for enviada à fonte de dados, retornará **SQL_NEED_DATA**. Isso alerta o quadro de que o valor do param `CLongBinary`para esta coluna é, na verdade, o endereço de um . O framework `SQLGetData` chama uma vez com um pequeno buffer, esperando que o driver retorne o comprimento real dos dados. Se o driver retornar o comprimento real do objeto grande binário (o BLOB), o MFC realoca o máximo de espaço necessário para buscar o BLOB. Se a fonte de dados retornar **SQL_NO_TOTAL,** indicando que não pode determinar o tamanho do BLOB, o MFC criará blocos menores. O tamanho inicial padrão é de 64K, e os blocos subseqüentes serão o dobro do tamanho; por exemplo, o segundo será 128K, o terceiro é 256K, e assim por diante. O tamanho inicial é configurável.

## <a name="not-binding-retrievingsending-data-directly-from-odbc-with-sqlgetdata"></a>Não vinculação: recuperando/enviando dados diretamente do ODBC com SQLGetData

Com este método, você contorna completamente as classes de banco de dados e lida com a coluna de dados longos você mesmo.

Vantagens:

Você pode armazenar dados em disco, se necessário, ou decidir dinamicamente quantos dados recuperar.

As desvantagens:

Você não recebe o suporte `Edit` `AddNew` ou o suporte da estrutura, e você`Delete` deve escrever o código para executar a funcionalidade básica ( funciona, porém, já que não é uma operação de nível de coluna).

Neste caso, a coluna de dados longos deve estar na lista selecionada do conjunto de registros, mas não deve ser vinculada à estrutura. Uma maneira de fazer isso é fornecer sua `GetDefaultSQL` própria declaração SQL via `CRecordset`ou `Open` como o argumento lpszSQL para a função, e não vincular a coluna extra com uma chamada de função RFX_. O ODBC exige que campos não vinculados apareçam à direita dos campos vinculados, por isso adicione sua coluna ou colunas desvinculadas ao final da lista selecionada.

> [!NOTE]
> Como sua coluna de dados longos não está vinculada à `CRecordset::Update` estrutura, as alterações nela não serão tratadas com chamadas. Você deve criar e enviar **INSERT** as instruções sql e **update** necessárias você mesmo.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
