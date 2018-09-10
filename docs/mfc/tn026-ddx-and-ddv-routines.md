---
title: 'TN026: Rotinas DDX e DDV | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- DDX
- DDV
dev_langs:
- C++
helpviewer_keywords:
- DDX (dialog data exchange), procedures
- TN026
- DDV (dialog data validation), procedures
ms.assetid: c2eba87a-4b47-4083-b28b-e2fa77dfb4c4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 18377d423ab150773ef5438f39c8e74914b5c425
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44317414"
---
# <a name="tn026-ddx-and-ddv-routines"></a>TN026: rotinas DDX e DDV

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve a troca de dados de caixa de diálogo (DDX) e a arquitetura de validação (DDV) de dados de caixa de diálogo. Ele também descreve como você pode escrever um procedimento funções DDX _ ou DDV_ e como você pode estender ClassWizard para usar suas rotinas.

## <a name="overview-of-dialog-data-exchange"></a>Visão geral da caixa de diálogo de troca de dados

Todas as funções de dados de caixa de diálogo são feitas com o código C++. Não há recursos especiais ou macros mágicas. O coração do mecanismo é uma função virtual que é substituída em cada classe de caixa de diálogo que caixa de diálogo de troca de dados e a validação. Ele sempre é encontrado neste formulário:

```cpp
void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);   // call base class

    //{{AFX_DATA_MAP(CMyDialog)
        <data_exchange_function_call>
        <data_validation_function_call>
    //}}AFX_DATA_MAP
}
```

Os comentários do formato especial AFX permitem ClassWizard localizar e editar o código nessa função. Código que não é compatível com ClassWizard deve ser colocado fora os comentários de formato especial.

No exemplo acima, \<data_exchange_function_call > está no formato:

```cpp
DDX_Custom(pDX, nIDC, field);
```

e \<data_validation_function_call > é opcional e está no formato:

```cpp
DDV_Custom(pDX, field, ...);
```

Mais de um par de funções DDX _ / DDV_ pode ser incluído em cada `DoDataExchange` função.

Consulte 'afxdd_.h' para obter uma lista de todas as rotinas de troca de dados de caixa de diálogo e rotinas de validação de dados de caixa de diálogo fornecidas com o MFC.

Dados de caixa de diálogo são exatamente isso: os dados de membro no `CMyDialog` classe. Ele não é armazenado em um struct ou algo semelhante.

## <a name="notes"></a>Observações

Embora, chamamos esses "dados de caixa de diálogo", todos os recursos estão disponíveis em qualquer classe derivada de `CWnd` e não são limitadas a apenas as caixas de diálogo.

Os valores iniciais de dados são definidos no construtor padrão do C++, geralmente em um bloco com `//{{AFX_DATA_INIT` e `//}}AFX_DATA_INIT` comentários.

`CWnd::UpdateData` é a operação que faz a inicialização e o erro de tratamento em torno da chamada para `DoDataExchange`.

Você pode chamar `CWnd::UpdateData` a qualquer momento para executar a validação e troca de dados. Por padrão `UpdateData`(verdadeiro) é chamado no padrão `CDialog::OnOK` manipulador e `UpdateData`(FALSE) é chamado no padrão `CDialog::OnInitDialog`.

A rotina DDV_ deve seguir a rotina de funções DDX _ imediatamente para que *campo*.

## <a name="how-does-it-work"></a>Como ele funciona

Você não precisa compreender o seguinte para usar dados de caixa de diálogo. No entanto, entender como isso funciona em segundo plano ajudará você escrever seu próprio procedimento de validação ou o exchange.

O `DoDataExchange` função de membro é muito parecido com o `Serialize` - função de membro, ele é responsável para obter ou definir os dados para/de um formulário externo (nesse caso, controles em uma caixa de diálogo) de/para dados de membro na classe. O *pDX* parâmetro é o contexto para fazer a troca de dados e é semelhante ao `CArchive` parâmetro `CObject::Serialize`. O *pDX* (um `CDataExchange` objeto) tem uma direção de sinalizador parecido com `CArchive` tem um sinalizador de direção:

- Se `!m_bSaveAndValidate`, em seguida, carregar o estado dos dados nos controles.

- Se `m_bSaveAndValidate`, em seguida, defina o estado dos dados dos controles.

A validação ocorre apenas quando `m_bSaveAndValidate` está definido. O valor de `m_bSaveAndValidate` é determinado pelo parâmetro BOOL para `CWnd::UpdateData`.

Há três outros interessante `CDataExchange` membros:

- `m_pDlgWnd`: A janela (normalmente, uma caixa de diálogo) que contém os controles. Isso é para impedir que os chamadores das funções globais funções DDX _ e DDV_ precisar passar 'this' para cada rotina DDX/DDV.

- `PrepareCtrl`, e `PrepareEditCtrl`: prepara um controle de caixa de diálogo para troca de dados. Armazena o identificador desse controle para definir o foco se uma validação falhar. `PrepareCtrl` é usado para controles não-edição e `PrepareEditCtrl` é usado para controles de edição.

- `Fail`: Chamado depois de colocar uma caixa de mensagem alertando o usuário para o erro de entrada. Essa rotina irá restaurar o foco para o último controle (a última chamada para `PrepareCtrl` ou `PrepareEditCtrl`) e lançar uma exceção. Essa função de membro pode ser chamada de funções DDX _ e DDV_ rotinas.

## <a name="user-extensions"></a>Extensões do usuário

Há várias maneiras de estender o mecanismo DDX/DDV padrão. Você pode:

- Adicione novos tipos de dados.

    ```cpp
    CTime
    ```

- Adicione novos procedimentos exchange (funções DDX _).

    ```cpp
    void PASCAL DDX_Time(CDataExchange* pDX, int nIDC, CTime& tm);
    ```

- Adicione novos procedimentos de validação (DDV_).

    ```cpp
    void PASCAL DDV_TimeFuture(CDataExchange* pDX, CTime tm, BOOL bFuture);
    // make sure time is in the future or past
    ```

- Passe expressões arbitrárias para os procedimentos de validação.

    ```cpp
    DDV_MinMax(pDX, age, 0, m_maxAge);
    ```

    > [!NOTE]
    > Tais expressões arbitrárias não pode ser editados por ClassWizard e, portanto, deve ser movidos para fora os comentários de formato especial (/ / {{AFX_DATA_MAP(CMyClass)).

Ter o `DoDialogExchange` função de membro incluem condicionais ou quaisquer outras instruções C++ válidas com chamadas de função de troca e validação misturadas.

```cpp
//{{AFX_DATA_MAP(CMyClass)
DDX_Check(pDX, IDC_SEX, m_bFemale);
DDX_Text(pDX, IDC_EDIT1, m_age);
//}}AFX_DATA_MAP
if (m_bFemale)
    DDV_MinMax(pDX, age, 0, m_maxFemaleAge);
else
    DDV_MinMax(pDX, age, 0, m_maxMaleAge);
```

> [!NOTE]
> Como mostrado acima, esse código não pode ser editado por ClassWizard e deve ser usado apenas para os comentários de formato especial.

## <a name="classwizard-support"></a>Suporte de ClassWizard

ClassWizard suporta um subconjunto das personalizações DDX/DDV, permitindo que você para integrar suas próprias rotinas de funções DDX _ e DDV_ a interface do usuário ClassWizard. Fazer isso é o único custo benéfico se você planeja reutilizar específicas rotinas DDX e DDV em um projeto ou em vários projetos.

Para fazer isso, as entradas especiais são feitas em DDX. CLW (versões anteriores do Visual C++ armazenavam essas informações em APSTUDIO. INI) ou em seu projeto. Arquivo CLW. As entradas especiais podem ser inserida na seção [geral Info] do seu projeto. Arquivo CLW ou na seção [ExtraDDX] o DDX. Arquivo CLW no diretório \Program Files\Microsoft Visual Studio\Visual \bin C + +. Você talvez precise criar o DDX. Arquivo CLW se ele ainda não existir. Se você planeja usar as rotinas de funções DDX _ / DDV_ personalizadas somente em um determinado projeto, adicione as entradas para a seção [geral Info] do seu projeto. CLW de arquivo em vez disso. Se você planeja usar as rotinas em vários projetos, adicione as entradas para a seção [ExtraDDX] DDX. CLW.

O formato geral dessas entradas especial é:

> ExtraDDXCount =*n*

em que *n* é o número de ExtraDDX? linhas a seguir, do formulário

> ExtraDDX? =*chaves*; *vb chaves*; *prompt*; *tipo*; *initValue*; *DDX_Proc* [; *DDV_Proc*; *prompt1*; *arg1* [; *prompt2*; *fmt2*]]

onde? é um número 1 - *n* que indica qual tipo DDX na lista que está sendo definido.

Cada campo é delimitado por um caractere ';'. Os campos e sua finalidade são descritos abaixo.

- *Chaves*

  Uma lista de caracteres únicos indicando para quais controles de caixa de diálogo esse tipo de variável é permitido.

  |Caractere|Controle permitido|
  |-|-|
  E | editar
  C | caixa de seleção de dois estados
  c | caixa de seleção de três estados
  R | primeiro botão de opção em um grupo
  L | caixa de lista não classificada
  l | caixa de lista classificada
  M | caixa de combinação (com o item de edição)
  N | lista suspensa não classificada
  n | lista suspensa classificado
  1 | Se a inserção DDX deve ser adicionada ao cabeçalho da lista (padrão é adicionar a parte final) isso geralmente é usado para rotinas DDX que transferir a propriedade de 'Controle'.

- *chaves de VB*

  Esse campo é usado apenas no produto 16 bits para os controles VBX (controles VBX não têm suporte no produto de 32 bits)

- *prompt*

  Cadeia de caracteres para colocar na caixa de combinação da propriedade (sem aspas)

- *type*

  Identificador único para o tipo emitir no arquivo de cabeçalho. Em nosso exemplo acima com DDX_Time, isso deve ser definido como CTime.

- *chaves de VB*

  Não usado nesta versão e deve estar sempre vazia

- *initValue*

  Valor inicial — 0 ou em branco. Se ela estiver vazia, nenhuma linha de inicialização será gravada na seção //{{AFX_DATA_INIT do arquivo de implementação. Uma entrada em branco deve ser usada para objetos C++ (como `CString`, `CTime`e assim por diante) que têm construtores que garantem a inicialização correta.

- *DDX_Proc*

  Identificador único para o procedimento de funções DDX _. O nome da função de C++ deve começar com "Funções DDX _", mas não inclua "Funções DDX _" no \<DDX_Proc > identificador. No exemplo acima, o \<DDX_Proc > identificador seria o momento. Quando o ClassWizard grava a chamada de função para o arquivo de implementação na {{seção AFX_DATA_MAP, ele acrescenta esse nome para funções DDX _, assim que chegam ao DDX_Time.

- *comment*

  Comentário para mostrar na caixa de diálogo de variável com esse DDX. Coloque qualquer texto que você gostaria de aqui e geralmente fornecem algo que descreve a operação executada pelo par DDX/DDV.

- *DDV_Proc*

  A parte DDV da entrada é opcional. Nem todas as rotinas DDX têm rotinas DDV correspondentes. Muitas vezes, é mais conveniente incluir a fase de validação como parte integrante da transferência. Isso é geralmente o caso quando sua rotina DDV não requer nenhum parâmetro, pois ClassWizard não oferece suporte a rotinas DDV sem parâmetros.

- *arg*

  Identificador único para o procedimento DDV_. O nome da função de C++ deve começar com "DDV_", mas não inclua "Funções DDX _" no \<DDX_Proc > identificador.

  *arg* é seguido por argumentos DDV 1 ou 2:

   - *promptN*

     Cadeia de caracteres para colocar acima Editar item (com & Accelerator).

   - *fmtN*

     Caractere de formato para o tipo de arg, um dos:

     |Caractere|Tipo|
     |-|-|
     d | int
     u | unsigned int
     D | Long int (ou seja, long)
     U | longo sem sinal (ou seja, DWORD)
     f | float
     F | double
     s | cadeia de caracteres

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)  
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)  
