---
title: 'TN026: Rotinas DDX e DDV | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 44a946b21908f45b595056a956c75b234fdbb886
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="tn026-ddx-and-ddv-routines"></a>TN026: rotinas DDX e DDV
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve a troca de dados de caixa de diálogo (DDX) e a arquitetura de validação (DDV) de dados de caixa de diálogo. Ele também descreve como escrever um procedimento DDX_ ou DDV_ e como você pode estender ClassWizard para usar suas rotinas.  
  
## <a name="overview-of-dialog-data-exchange"></a>Visão geral de troca de dados de caixa de diálogo  
 Todas as funções de dados de caixa de diálogo são realizadas com o código C++. Não existem recursos especiais ou magic macros. O núcleo do mecanismo é uma função virtual for substituída em todas as classes de caixa de diálogo que caixa de diálogo de troca de dados e a validação. Ele sempre foi encontrado neste formulário:  
  
```  
void CMyDialog::DoDataExchange(CDataExchange* pDX)  
{  
    CDialog::DoDataExchange(pDX);
*// call base class  
 *//{{AFX_DATA_MAP(CMyDialog)  
 <data_exchange_function_call>  
 <data_validation_function_call> *//}}AFX_DATA_MAP  
}  
```  
  
 Os comentários do formato especial AFX permitem ClassWizard localizar e editar o código nessa função. Código que não é compatível com ClassWizard deve ser colocado fora os comentários de formato especial.  
  
 No exemplo acima, < data_exchange_function_call > está no formato:  
  
```  
DDX_Custom(pDX,
    nIDC,
    field);
```  
  
 e < data_validation_function_call > é opcional e está no formato:  
  
```  
DDV_Custom(pDX,
    field, ...);
```  
  
 Mais de um par DDX_/DDV_ pode ser incluído em cada `DoDataExchange` função.  
  
 Consulte 'afxdd_.h' para obter uma lista de todas as rotinas de troca de dados de caixa de diálogo e rotinas de validação de dados de caixa de diálogo fornecidas com MFC.  
  
 Dados de caixa de diálogo são exatamente isso: dados de membro no **CMyDialog** classe. Não são armazenadas em uma estrutura ou algo semelhante.  
  
## <a name="notes"></a>Observações  
 Embora chamamos esses dados de caixa de diálogo"", todos os recursos estão disponíveis em qualquer classe derivada de `CWnd` e não está limitado a apenas as caixas de diálogo.  
  
 Os valores iniciais de dados são definidos no construtor de C++ padrão, geralmente em um bloco com `//{{AFX_DATA_INIT` e `//}}AFX_DATA_INIT` comentários.  
  
 `CWnd::UpdateData` é a operação que faz a inicialização e o erro tratamento em torno da chamada para `DoDataExchange`.  
  
 Você pode chamar `CWnd::UpdateData` a qualquer momento para executar a validação e troca de dados. Por padrão `UpdateData`(TRUE) é chamado no padrão `CDialog::OnOK` manipulador e `UpdateData`(FALSE) é chamado no padrão `CDialog::OnInitDialog`.  
  
 A rotina DDV_ deve seguir imediatamente a rotina DDX_ para que *campo*.  
  
## <a name="how-does-it-work"></a>Como funciona  
 Você não precisa compreender o seguinte para usar dados de caixa de diálogo. No entanto, entender como isso funciona nos bastidores ajudará você escrever seu próprio procedimento de validação ou o exchange.  
  
 O `DoDataExchange` função de membro é muito parecida com a `Serialize` função de membro - ele é responsável por obter ou definir dados para/de um formulário externo (nesse caso, controles em uma caixa de diálogo) de/para dados de membro na classe. O `pDX` parâmetro é o contexto para fazer a troca de dados e é semelhante de `CArchive` parâmetro `CObject::Serialize`. O `pDX` (uma `CDataExchange` objeto) tem uma direção sinalizador parecido com `CArchive` tem um sinalizador de direção:  
  
-   Se **! m_bSaveAndValidate**, em seguida, carregar o estado de dados em controles.  
  
-   Se `m_bSaveAndValidate`, em seguida, defina o estado de dados dos controles.  
  
 A validação ocorre apenas quando `m_bSaveAndValidate` está definido. O valor de `m_bSaveAndValidate` é determinado pelo parâmetro BOOL para `CWnd::UpdateData`.  
  
 Há três outros interessantes `CDataExchange` membros:  
  
- `m_pDlgWnd`: A janela (normalmente uma caixa de diálogo) que contém os controles. Isso serve para impedir que os chamadores das funções globais DDX_ e DDV_ precisar passar 'this' para cada rotina DDX/DDV.  
  
- `PrepareCtrl`, e `PrepareEditCtrl`: prepara um controle de caixa de diálogo para troca de dados. Armazena o identificador do controle para definir o foco se uma validação falhar. `PrepareCtrl` é usado para controles nonedit e `PrepareEditCtrl` é usado para controles de edição.  
  
- **Falha**: chamado depois de abrir uma caixa de mensagem de alerta o usuário o erros de entrada. Esta rotina restaurará o foco para o último controle (a última chamada a `PrepareCtrl` / `PrepareEditCtrl`) e gerará uma exceção. Essa função de membro pode ser chamada de rotinas DDX_ e DDV_.  
  
## <a name="user-extensions"></a>Extensões de usuário  
 Há várias maneiras de estender o mecanismo DDX/DDV padrão. Você pode:  
  
-   Adicione novos tipos de dados.  
  
 ```  
    CTime 
 ```  
  
-   Adicione novos procedimentos do exchange (DDX_).  
  
 ```  
    void PASCAL DDX_Time(CDataExchange* pDX,
    int nIDC,
    CTime& tm);

 ```  
  
-   Adicione novos procedimentos de validação (DDV_).  
  
 ```  
    void PASCAL DDV_TimeFuture(CDataExchange* pDX,
    CTime tm,
    BOOL bFuture);
*// make sure time is in the future or past  
 ```  
  
-   Passe expressões arbitrárias para os procedimentos de validação.  
  
 ```  
    DDV_MinMax(pDX,
    age,
    0,
    m_maxAge);

 ```  
  
    > [!NOTE]
    >  Tais expressões arbitrárias não pode ser editados pelo ClassWizard e, portanto, deve ser movidos para fora os comentários de formato especial (/ / {{AFX_DATA_MAP(CMyClass)).  
  
 Ter o **DoDialogExchange** função membro incluem condicionais ou qualquer outra instrução C++ válida com misturado chamadas de função do exchange e a validação.  
  
```  
//{{AFX_DATA_MAP(CMyClass)  
DDX_Check(pDX,
    IDC_SEX,
    m_bFemale);

DDX_Text(pDX,
    IDC_EDIT1,
    m_age);

//}}AFX_DATA_MAP  
if (m_bFemale)  
    DDV_MinMax(pDX,
    age,
    0,
    m_maxFemaleAge);

else  
    DDV_MinMax(pDX,
    age,
    0,
    m_maxMaleAge);
```  
  
> [!NOTE]
>  Como mostrado acima, esse código não pode ser editado pelo ClassWizard e deve ser usado somente fora os comentários de formato especial.  
  
## <a name="classwizard-support"></a>Suporte de ClassWizard  
 ClassWizard oferece suporte a um subconjunto das personalizações DDX/DDV, permitindo que você integre suas próprias rotinas DDX_ e DDV_ na interface de usuário ClassWizard. Isso é apenas custo útil se você planejar reutilizar específicas rotinas DDX e DDV em um projeto ou em vários projetos.  
  
 Para fazer isso, as entradas especiais são feitas no DDX. CLW (versões anteriores do Visual C++ armazenavam essas informações em APSTUDIO. INI) ou em seu projeto. Arquivo CLW. As entradas especiais podem ser inserido na seção [geral Info] do seu projeto. Arquivo CLW ou na seção [ExtraDDX] o DDX. Arquivo CLW no diretório \Program Files\Microsoft Studio\Visual Visual C + + \bin. Talvez seja necessário criar o DDX. Arquivo CLW se ele ainda não existir. Se você planeja usar as rotinas DDX_/DDV_ personalizadas somente em um determinado projeto, adicione as entradas à seção [geral Info] do seu projeto. CLW de arquivo em vez disso. Se você planeja usar as rotinas em vários projetos, adicione as entradas para a seção [ExtraDDX] DDX. CLW.  
  
 O formato geral dessas entradas especial é:  
  
```  
ExtraDDXCount=n  
```  
  
 onde n é o número de linhas de ExtraDDX a seguir  
  
```  
ExtraDDX=<keys>;<vb-keys>; <prompt>; <type>; <initValue>; <DDX_Proc>  
[;<DDV_Proc>; <prompt1>; <arg1>; [<prompt2>; <fmt2>]]  
```  
  
 onde é um número 1 - n que indica qual tipo DDX na lista que está sendo definido.  
  
 Cada campo é delimitado por um caractere ';'. Os campos e sua finalidade são descritos abaixo.  
  
 \<chaves >  
 = lista de caracteres únicas que indica para quais controles de caixa de diálogo esse tipo de variável é permitido.  
  
 E = editar  
  
 C = caixa de seleção de dois estados  
  
 c = caixa de seleção de três estados  
  
 R = primeiro botão de opção em um grupo  
  
 L = caixa de lista não classificada  
  
 l = caixa de lista classificada  
  
 M = caixa de combinação (com o item de edição)  
  
 N = lista não classificada  
  
 n = lista classificada  
  
 1 = se a inserção DDX deve ser adicionada ao início da lista (o padrão é adicionado à parte final) isso geralmente é usado para rotinas DDX que transferir a propriedade 'Controle'.  
  
 \<chaves de VB >  
 Esse campo é usado somente dentro do produto de 16 bits para controles VBX (VBX controles não têm suporte do produto de 32 bits)  
  
 \<prompt >  
 Cadeia de caracteres para a caixa de combinação de propriedade (sem aspas)  
  
 \<type>  
 Identificador único para o tipo de emissão no arquivo de cabeçalho. Em nosso exemplo acima com DDX_Time, isso deve ser definido como CTime.  
  
 \<chaves de VB >  
 Não é usada nesta versão e deve estar sempre vazia  
  
 \<initValue >  
 Valor inicial — 0 ou em branco. Se ela estiver vazia, nenhuma linha de inicialização será gravada na seção //{{AFX_DATA_INIT do arquivo de implementação. Uma entrada em branco deve ser usada para objetos C++ (como `CString`, `CTime`e assim por diante) que tenham construtores que garantem a inicialização correta.  
  
 < DDX_Proc >  
 Identificador único para o procedimento DDX_. O nome da função C++ deve começar com "DDX_", mas não incluem "DDX_" no identificador de < DDX_Proc >. No exemplo acima, o identificador de < DDX_Proc > seria tempo. Quando ClassWizard grava a chamada de função para o arquivo de implementação no {{seção AFX_DATA_MAP, ele anexa esse nome ao DDX_, assim que chegam ao DDX_Time.  
  
 \<comentário >  
 Comentário para mostrar na caixa de diálogo de variável com este DDX. Coloca qualquer texto que você gostaria que aqui e geralmente fornecem algo que descreve a operação executada pelo par DDX/DDV.  
  
 < DDV_Proc >  
 A parte DDV da entrada é opcional. Nem todas as rotinas DDX têm rotinas DDV correspondentes. Geralmente, é mais conveniente incluir a fase de validação como parte integrante da transferência. Isso é geralmente o caso quando sua rotina DDV não requer nenhum parâmetro, como ClassWizard não oferece suporte a rotinas DDV sem parâmetros.  
  
 \<arg >  
 Identificador único para o procedimento DDV_. O nome da função C++ deve começar com "DDV_", mas não incluem "DDX_" no identificador de < DDX_Proc >.  
  
 seguido por argumentos DDV 1 ou 2:  
  
 \<promptX >  
 cadeia de caracteres para colocar acima Editar item (com & Accelerator)  
  
 \<fmtX >  
 caracteres de formato para o tipo de argumento, uma das  
  
 d = int  
  
 u = sem sinal  
  
 D = int longo (ou seja, long)  
  
 U = longo não assinado (ou seja, DWORD)  
  
 f = float  
  
 F = duplo  
  
 s = cadeia de caracteres  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

