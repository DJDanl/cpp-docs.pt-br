---
title: 'TN026: rotinas DDX e DDV'
ms.date: 06/28/2018
f1_keywords:
- DDX
- DDV
helpviewer_keywords:
- DDX (dialog data exchange), procedures
- TN026
- DDV (dialog data validation), procedures
ms.assetid: c2eba87a-4b47-4083-b28b-e2fa77dfb4c4
ms.openlocfilehash: 711d433b51ca09836f372d09a11f86c28b82cce6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370340"
---
# <a name="tn026-ddx-and-ddv-routines"></a>TN026: rotinas DDX e DDV

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota descreve a arquitetura DDX (Exchange) de troca de dados de diálogo e validação de dados de diálogo (DDV). Ele também descreve como você escreve um procedimento de DDX_ ou DDV_ e como você pode estender o ClassWizard para usar suas rotinas.

## <a name="overview-of-dialog-data-exchange"></a>Visão geral do Intercâmbio de Dados de Diálogo

Todas as funções de dados de diálogo são feitas com código C++. Não há recursos especiais ou macros mágicas. O coração do mecanismo é uma função virtual que é substituída em todas as classes de diálogo que dialogam com a troca e validação de dados. É sempre encontrado nesta forma:

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

O formato especial de comentários AFX permite que o ClassWizard localize e edite o código dentro desta função. O código que não é compatível com o ClassWizard deve ser colocado fora dos comentários de formato especial.

No exemplo acima, \<data_exchange_function_call> está na forma:

```cpp
DDX_Custom(pDX, nIDC, field);
```

e \<data_validation_function_call> é opcional e está na forma:

```cpp
DDV_Custom(pDX, field, ...);
```

Mais de um par de DDX_/DDV_ pode ser incluído em cada `DoDataExchange` função.

Consulte 'afxdd_.h' para obter uma lista de todas as rotinas de troca de dados de diálogo e rotinas de validação de dados de diálogo fornecidas com MFC.

Os dados de diálogo são `CMyDialog` apenas isso: dados de membros na classe. Não é armazenado em uma estrutura ou qualquer coisa semelhante.

## <a name="notes"></a>Observações

Embora chamemos isso de "dados de diálogo", todos `CWnd` os recursos estão disponíveis em qualquer classe derivada e não se limitam apenas a diálogos.

Os valores iniciais dos dados são definidos no construtor `//{{AFX_DATA_INIT` `//}}AFX_DATA_INIT` C++ padrão, geralmente em um bloco com e comentários.

`CWnd::UpdateData`é a operação que faz a inicialização e `DoDataExchange`o manuseio de erros em torno da chamada para .

Você pode `CWnd::UpdateData` ligar a qualquer momento para realizar a troca e validação de dados. Por `UpdateData`padrão (TRUE) é `CDialog::OnOK` chamado `UpdateData`no manipulador padrão e `CDialog::OnInitDialog`(FALSE) é chamado no padrão .

A rotina DDV_ deve seguir imediatamente a rotina DDX_ para esse *campo.*

## <a name="how-does-it-work"></a>Como funciona

Você não precisa entender o seguinte para usar os dados de diálogo. No entanto, entender como isso funciona nos bastidores ajudará você a escrever seu próprio procedimento de troca ou validação.

A `DoDataExchange` função de membro `Serialize` é muito parecida com a função do membro - ela é responsável por obter ou definir dados para/a partir de uma forma externa (neste caso controla em uma caixa de diálogo) de/para dados de membros na classe. O parâmetro *pDX* é o contexto para fazer `CArchive` a troca `CObject::Serialize`de dados e é semelhante ao parâmetro para . O *pDX* `CDataExchange` (um objeto) tem `CArchive` uma bandeira de direção muito parecida com uma bandeira de direção:

- Se `!m_bSaveAndValidate`, em seguida, carregar o estado de dados nos controles.

- Se `m_bSaveAndValidate`, em seguida, definir o estado de dados a partir dos controles.

A validação `m_bSaveAndValidate` só ocorre quando está definida. O valor `m_bSaveAndValidate` do é determinado pelo `CWnd::UpdateData`parâmetro BOOL para .

Há três outros `CDataExchange` membros interessantes:

- `m_pDlgWnd`: A janela (geralmente uma caixa de diálogo) que contém os controles. Isso é para evitar que os chamadores das funções globais DDX_ e DDV_ tenham que passar 'isso' para cada rotina de DDX/DDV.

- `PrepareCtrl`, `PrepareEditCtrl`e : Prepara um controle de diálogo para troca de dados. Armazena a alça do controle para definir o foco se uma validação falhar. `PrepareCtrl`é usado para controles não-edição e `PrepareEditCtrl` é usado para controles de edição.

- `Fail`: Chamado depois de trazer uma caixa de mensagem alertando o usuário para o erro de entrada. Essa rotina restaurará o foco ao último `PrepareCtrl` controle `PrepareEditCtrl`(a última chamada ou ) e abrirá uma exceção. Esta função de membro pode ser chamada tanto de DDX_ quanto de DDV_ rotinas.

## <a name="user-extensions"></a>Extensões do usuário

Existem várias maneiras de estender o mecanismo DDX/DDV padrão. Você pode:

- Adicione novos tipos de dados.

    ```cpp
    CTime
    ```

- Adicione novos procedimentos de troca (DDX_).

    ```cpp
    void PASCAL DDX_Time(CDataExchange* pDX, int nIDC, CTime& tm);
    ```

- Adicione novos procedimentos de validação (DDV_).

    ```cpp
    void PASCAL DDV_TimeFuture(CDataExchange* pDX, CTime tm, BOOL bFuture);
    // make sure time is in the future or past
    ```

- Passe expressões arbitrárias aos procedimentos de validação.

    ```cpp
    DDV_MinMax(pDX, age, 0, m_maxAge);
    ```

    > [!NOTE]
    > Essas expressões arbitrárias não podem ser editadas pelo ClassWizard e, portanto, devem ser movidas fora dos comentários de formato especial (//{{AFX_DATA_MAP(CMyClass)).

Que `DoDialogExchange` a função de membro inclua condicionais ou quaisquer outras instruções C++ válidas com chamadas de função de troca e validação misturadas.

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
> Como mostrado acima, tal código não pode ser editado pelo ClassWizard e deve ser usado apenas fora dos comentários de formato especial.

## <a name="classwizard-support"></a>Suporte classwizard

O ClassWizard suporta um subconjunto de personalizações DDX/DDV, permitindo que você integre suas próprias rotinas de DDX_ e DDV_ na interface de usuário do ClassWizard. Fazer isso só é benéfico se você planeja reutilizar determinadas rotinas de DDX e DDV em um projeto ou em muitos projetos.

Para isso, entradas especiais são feitas no DDX. CLW (versões anteriores do Visual C++ armazenavam essas informações no APSTUDIO. INI) ou no seu projeto. Arquivo CLW. As entradas especiais podem ser inseridas na seção [Informações Gerais] do seu projeto. Arquivo CLW ou na seção [ExtraDDX] do DDX. Arquivo CLW no diretório \Program Files\Microsoft Visual Studio\Visual C++\bin. Você pode precisar criar o DDX. Arquivo CLW se ele ainda não existe. Se você planeja usar as rotinas personalizadas de DDX_/DDV_ apenas em um determinado projeto, adicione as entradas à seção [Informações Gerais] do seu projeto . Arquivo CLW em vez disso. Se você planeja usar as rotinas em muitos projetos, adicione as entradas à seção [ExtraDDX] do DDX. Clw.

O formato geral dessas entradas especiais é:

> ExtraDDXCount=*n*

onde *n* é o número de ExtraDDX? linhas a seguir, da forma

> Chaves ExtraDDX?=*keys*; *vb-keys*; *prompt*; *tipo;* *initValue*; *DDX_Proc* [; *DDV_Proc;* *prompt1*; *arg1* [; *prompt2*; *fmt2*]]

Onde? é um número 1 - *n* indicando qual tipo De DDX na lista que está sendo definida.

Cada campo é delimitado por um caractere ';'. Os campos e seus propósitos são descritos abaixo.

- *Chaves*

  Uma lista de caracteres únicos indicando para o qual a caixa de diálogo controla esse tipo de variável é permitida.

  |Caractere|Controle permitido|
  |-|-|
  E | editar
  C | caixa de seleção de dois estados
  c | caixa de seleção tri-estado
  R | primeiro botão de rádio em um grupo
  L | caixa de lista não sortida
  l | caixa de lista classificada
  M | caixa de combinação (com item de edição)
  N | lista de quedas não classificadas
  n | lista de quedas classificadas
  1 | se a inserção DDX deve ser adicionada ao chefe da lista (padrão é adicionar à cauda) Isso é geralmente usado para rotinas DDX que transferem a propriedade 'Control'.

- *vb-chaves*

  Este campo é usado apenas no produto de 16 bits para controles VBX (os controles VBX não são suportados no produto de 32 bits)

- *Prompt*

  String to place na caixa de combinação Propriedade (sem aspas)

- *type*

  Identificador único para tipo para emitir no arquivo de cabeçalho. No nosso exemplo acima com DDX_Time, isso seria definido como CTime.

- *vb-chaves*

  Não usado nesta versão e deve estar sempre vazio

- *initValue*

  Valor inicial — 0 ou em branco. Se estiver em branco, nenhuma linha de inicialização será escrita na seção //{{AFX_DATA_INIT do arquivo de implementação. Uma entrada em branco deve ser usada `CString`para `CTime`objetos C++ (como , e assim por diante) que tenham construtores que garantam a inicialização correta.

- *DDX_Proc*

  Identificador único para o procedimento DDX_. O nome da função C++ deve começar com "DDX_", \<mas não inclua "DDX_" no identificador de> DDX_Proc. No exemplo acima, \<o DDX_Proc identificador> seria Time. Quando o ClassWizard grava a chamada de função para o arquivo de implementação na seção {{AFX_DATA_MAP, ele anexa esse nome para DDX_, chegando assim a DDX_Time.

- *comment*

  Comentário para mostrar em diálogo para variável com este DDX. Coloque qualquer texto que você quiser aqui, e geralmente forneça algo que descreva a operação realizada pelo par DDX/DDV.

- *DDV_Proc*

  A parte DDV da entrada é opcional. Nem todas as rotinas de DDX têm rotinas de DDV correspondentes. Muitas vezes, é mais conveniente incluir a fase de validação como parte integrante da transferência. Isso é frequentemente o caso quando sua rotina de DDV não requer parâmetros, porque o ClassWizard não suporta rotinas de DDV sem quaisquer parâmetros.

- *Arg*

  Identificador único para o procedimento DDV_. O nome da função C++ deve começar com "DDV_", \<mas não incluir "DDX_" no identificador de> DDX_Proc.

  *arg* é seguido por 1 ou 2 args DDV:

  - *promptN*

      Corda para colocar acima do item de edição (com & para acelerador).

  - *fmtN*

      Caractere de formato para o tipo arg, um dos seguintes:

      |Caractere|Type|
      |-|-|
      |d | INT|
      |u | unsigned int|
      |D | int longo (isto é, longo)|
      |U | longo sem assinatura (isto é, DWORD)|
      |f | FLOAT|
      |F | double|
      |s | string|

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
