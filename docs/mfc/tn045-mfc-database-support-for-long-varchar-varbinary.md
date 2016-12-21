---
title: "TN045: suporte a MFC/banco de dados para Varchar/Varbinary longo | Microsoft Docs"
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
  - "vc.mfc.data"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "TN045"
  - "tipo de dados Varbinary"
  - "tipo de dados Varchar"
ms.assetid: cf572c35-5275-45b5-83df-5f0e36114f40
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN045: suporte a MFC/banco de dados para Varchar/Varbinary longo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve como recuperar e enviar os tipos de dados ODBC **SQL\_LONGVARCHAR** e de **SQL\_LONGVARBINARY** usando as classes da base de dados de MFC.  
  
## Visão geral do suporte ao longo de Varchar\/Varbinary  
 Os tipos de dados ODBC **SQL\_LONG\_VARCHAR** e de **SQL\_LONGBINARY** \(mencionados aqui como colunas de dados\) demoradas podem manter grandes volumes de dados.  Há 3 modos que você pode tratar desses dados:  
  
-   Associá\-los a `CString`\/`CByteArray`.  
  
-   Associá\-lo a `CLongBinary`.  
  
-   O não associar de todo o e não o recuperar e não o enviar o valor de dados longo manualmente, independentemente das classes base de dados do.  
  
 Cada um dos três métodos tem vantagens e desvantagens.  
  
 As colunas de dados de longa execução não há suporte para parâmetros a uma consulta.  Só há suporte para outputColumns.  
  
## Associando uma coluna de dados maior a um CString\/CByteArray  
 Vantagens:  
  
 Essa abordagem é simples e compreender, você trabalha com classes familiares.  A estrutura fornece suporte de `CFormView` para `CString` com `DDX_Text`.  Você tem muitos da funcionalidade geral da cadeia de caracteres ou da coleção com as classes de `CString` e de `CByteArray` , e você pode controlar a quantidade de memória alocada localmente para conter o valor de dados.  A estrutura mantém uma cópia antiga de dados do campo durante **Editar** ou chamadas de função de `AddNew` , e a estrutura pode detectar automaticamente alterações nos dados.  
  
> [!NOTE]
>  Desde que `CString` é criado para funcionar em dados de caracteres, e `CByteArray` para trabalhar em dados binários, é recomendado que você coloque os dados de caractere \(**SQL\_LONGVARCHAR**\) em `CString`, e os dados binários \(**SQL\_LONGVARBINARY**\) em `CByteArray`.  
  
 As funções de RFX para `CString` e `CByteArray` têm um argumento adicional que permite substituir o tamanho padrão da memória alocada para conter o valor recuperado da coluna de dados.  Observe o argumento de nMaxLength nas declarações de função:  
  
```  
void AFXAPI RFX_Text(CFieldExchange* pFX, const char *szName,  
    CString& value, int nMaxLength = 255, int nColumnType =  
    SQL_VARCHAR);  
  
void AFXAPI RFX_Binary(CFieldExchange* pFX, const char *szName,   
    CByteArray& value,int nMaxLength = 255);  
```  
  
 Se você recuperar dados de uma coluna longa em `CString` ou em `CByteArray`, a quantidade máxima de dados é retornada, por padrão, 255 bytes.  Qualquer coisa além disso é ignorado.  Nesse caso, a estrutura gerará a exceção **AFX\_SQL\_ERROR\_DATA\_TRUNCATED**.  Felizmente, você pode aumentar o nMaxLength explicitamente os valores maiores, até **MAXINT**.  
  
> [!NOTE]
>  O valor de nMaxLength é usado por MFC para definir o buffer local da função de **SQLBindColumn** .  Este é o buffer local para armazenamento de dados e não afeta a verdade a quantidade de dados retornados pelo driver ODBC.  `RFX_Text` e `RFX_Binary` só fazem uma chamada usando **SQLFetch** para recuperar os dados do base de dados de back\-end.  Cada driver ODBC tem uma limitação diferente na quantidade de dados que podem ser retornadas em um único busca.  Esse limite pode ser muito menor que o valor definido no nMaxLength, nesse caso **AFX\_SQL\_ERROR\_DATA\_TRUNCATED** a exceção será lançada.  Nestas circunstâncias, alterne para usar `RFX_LongBinary` em vez de `RFX_Text` ou de `RFX_Binary` de forma que todos os dados podem ser recuperados.  
  
 ClassWizard associará **SQL\_LONGVARCHAR** a `CString`, ou **SQL\_LONGVARBINARY** a `CByteArray` para você.  Se você desejar atribuir mais de 255 bytes em que você recupera a coluna de dados longa, você pode fornecer um valor explícito para o nMaxLength.  
  
 Quando uma coluna de dados longa for associada a `CString` ou a `CByteArray`, atualizando o trabalho de campo somente o mesmo de quando for associada a um SQL\_**VARCHAR** ou a SQL\_**VARBINARY**.  Durante **Editar**, o valor de dados está armazenado em cachê acionado e depois quando comparado **Atualizar** é chamado para detectar alterações no valor de dados e definir adequadamente os valores incorretos e nulos para a coluna.  
  
## Associando uma coluna de dados maior a um CLongBinary  
 Se a coluna de dados longa pode conter mais bytes de **MAXINT** de dados, você deve considerar provavelmente recuperar\-la em `CLongBinary`.  
  
 Vantagens:  
  
 Isso recupera uma coluna longa de dados inteira, até a memória disponível.  
  
 Desvantagens:  
  
 Os dados são mantidos na memória.  Essa abordagem também é proibitivamente caro para grandes quantidades de dados.  Você deve chamar `SetFieldDirty` para que o membro de dados associados certifique\-se de que o campo está incluído em uma operação de **Atualizar** .  
  
 Se você recuperar colunas de dados longas em `CLongBinary`, as classes da base de dados verificarão o tamanho total da coluna de dados longa, então atribuem um segmento de memória de `HGLOBAL` grande o suficiente para guardará\-lo o valor de dados.  As classes de base de dados recuperam em todo o valor de dados em `HGLOBAL`atribuído.  
  
 Se a fonte de dados não pode retornar o tamanho estimado da coluna de dados longa, a estrutura gerará a exceção **AFX\_SQL\_ERROR\_SQL\_NO\_TOTAL**.  Se a tentativa para alocar `HGLOBAL` falhar, uma exceção padrão de memória será gerada.  
  
 ClassWizard associará **SQL\_LONGVARCHAR** ou **SQL\_LONGVARBINARY** a `CLongBinary` para você.  `CLongBinary` selecione como a variável na caixa de diálogo da variável de membro adicionar.  ClassWizard irá adicionar uma chamada de `RFX_LongBinary` a sua chamada de `DoFieldExchange` e será incrementado o número total de campos associados.  
  
 Para atualizar valores de dados longos da coluna, primeiramente certifique\-se que `HGLOBAL` atribuído é grande o suficiente para manter seus novos dados chamando **::GlobalSize** no membro de `m_hData` de `CLongBinary`.  Se for muito pequeno, liberar `HGLOBAL` e atribua um o tamanho apropriado.  `m_dwDataLength` em definido para refletir o novo tamanho.  
  
 Caso contrário, se `m_dwDataLength` é maior que o tamanho dos dados que você estiver substituindo, você poderá liberar e realocar `HGLOBAL`, ou deixe\-o atribuído.  Verifique indicar o número de bytes realmente usados em `m_dwDataLength`.  
  
## Como atualizar um CLongBinary funciona  
 Não é necessário entender como atualizar `CLongBinary` funciona, mas pode ser útil como um exemplo de como enviar valores de dados longos a uma fonte de dados, se você escolher o terceiro método, descrita abaixo.  
  
> [!NOTE]
>  Para que um campo de `CLongBinary` é incluído em uma atualização, você deve chamar explicitamente `SetFieldDirty` para o campo.  Se você fizer alguma alteração a um campo, definindo o incluir nulo, você deve chamar `SetFieldDirty`.  Você também deve chamar `SetFieldNull`, com o segundo parâmetro que é **Falso**, para marcar o campo como tendo um valor.  
  
 Ao atualizar um campo de `CLongBinary` , o mecanismo de **DATA\_AT\_EXEC** ODBC do uso de classes base de dados do \(consulte a documentação do ODBC no argumento de rgbValue de **SQLSetPos** \).  Quando a estrutura prepara a inserção ou de atualização, em vez de aponte para `HGLOBAL` que contém os dados, *o endereço* de `CLongBinary` são definidos como *o valor* da coluna por vez, e o indicador de comprimento definido como **SQL\_DATA\_AT\_EXEC**.  Posteriormente, quando a instrução de atualização é enviada à fonte de dados, **SQLExecDirect** retornará **SQL\_NEED\_DATA**.  Isso alerta a estrutura que o valor do parâmetro para essa coluna é o endereço de `CLongBinary`.  A estrutura **SQLGetData** chama uma vez com um buffer pequeno, aguardando que o driver retornar o comprimento real dos dados.  Se o driver retorna o comprimento real de objeto binário grande \(BLOB\), o MFC o realoca tanto espaço quanto necessário para buscar o BLOB.  Se a fonte de dados retornar **SQL\_NO\_TOTAL**, indicando que não pode determinar o tamanho do BLOB, MFC criará blocos menores.  O tamanho inicial padrão é 64K, os blocos e subsequentes serão double o tamanho; por exemplo, o segundo será 128K, a terceira é 256K, e assim por diante.  O tamanho inicial é configurável.  
  
## Não se associando: Recuperar\/que envia dados diretamente de ODBC com SQLGetData  
 Com esse método você ignora completamente as classes da base de dados, e o negócio com a coluna de dados longa que você mesmo.  
  
 Vantagens:  
  
 Você pode armazenar em cachê dados em disco se necessário, ou decida dinamicamente a quantidade de dados a ser recuperado.  
  
 Desvantagens:  
  
 Não terá suporte de **Editar** ou de `AddNew` da estrutura, e você deve escrever o código você mesmo para executar a funcionalidade básica \(**Excluir** funciona apesar de, desde que não é uma operação de nível de coluna\).  
  
 Nesse caso, a coluna longa de dados deve estar na lista de seleção do conjunto de registros, mas não deve ser associada pela estrutura.  Uma forma de fazer isso é fornecer sua própria instrução SQL por meio de `GetDefaultSQL` ou como o argumento de lpszSQL à função de `CRecordset`**Abrir** , e não associar a coluna adicional com uma chamada de função de RFX\_.  ODBC exige que os campos associados são exibidas à direita dos campos associados, o que adiciona suas coluna ou colunas desassociadas ao final da lista de seleção.  
  
> [!NOTE]
>  Como a coluna de dados longa não é associada pela estrutura, as alterações feitas nele não serão manipuladas com chamadas de `CRecordset::Update` .  Você deve criar e enviar SQL necessário **INSERIR** e instruções de **ATUALIZAR** você mesmo.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)