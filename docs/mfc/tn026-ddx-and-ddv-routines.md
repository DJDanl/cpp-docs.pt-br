---
title: "TN026: rotinas DDX e DDV | Microsoft Docs"
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
  - "DDX"
  - "DDV"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DDV (validação dos dados da caixa de diálogo), procedimentos"
  - "DDX (troca de dados da caixa de diálogo), procedimentos"
  - "TN026"
ms.assetid: c2eba87a-4b47-4083-b28b-e2fa77dfb4c4
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN026: rotinas DDX e DDV
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve a caixa de diálogo arquitetura de \(DDV\) de troca de dados \(DDX\) e da caixa de diálogo de validação de dados.  Também descreve como você escrever um procedimento de DDX\_ ou de DDV\_ e como você pode estender ClassWizard para usar suas rotinas.  
  
## Visão geral da caixa de diálogo de troca de dados  
 Todas as funções dos dados na caixa de diálogo são feitas com código C\+\+.  Não há nenhum recurso especial ou macro mágico.  O centro do mecanismo é uma função virtual que foi substituída em cada classe da caixa de diálogo que faz a caixa de diálogo troca de dados e a validação.  Sempre é encontrado neste formato:  
  
```  
void CMyDialog::DoDataExchange(CDataExchange* pDX)  
{  
    CDialog::DoDataExchange(pDX);    // call base class  
  
    //{{AFX_DATA_MAP(CMyDialog)  
        <data_exchange_function_call>  
        <data_validation_function_call>  
    //}}AFX_DATA_MAP  
}  
```  
  
 Os comentários especiais de AFX de formato permitem que ClassWizard localize e editar o código dentro dessa função.  Código que não é compatível com ClassWizard deve ser colocado fora observações especiais de formato.  
  
 No exemplo anterior, \<o data\_exchange\_function\_call\> está no formato:  
  
```  
DDX_Custom(pDX, nIDC, field);  
```  
  
 e \<o data\_validation\_function\_call\> é opcional e está no formato:  
  
```  
DDV_Custom(pDX, field, ...);  
```  
  
 Mais de um par de DDX\_\/DDV\_ pode ser incluído em cada função de `DoDataExchange` .  
  
 Consulte “afxdd\_.h” para uma lista de todas as rotinas de troca de dados da caixa de diálogo e rotinas de validação de dados na caixa de diálogo MFC fornecidas com o.  
  
 Os dados da caixa de diálogo são apenas o seguinte: dados de membros na classe de **CMyDialog** .  Não são armazenadas em uma estrutura ou em qualquer coisa semelhante.  
  
## Notas  
 Embora esses nós chamemos de dados “caixa de diálogo,” todos os recursos estão disponíveis em qualquer classe derivada de `CWnd` e não são limitados apenas as caixas de diálogo.  
  
 Os valores de dados iniciais são definidos no construtor padrão do C\+\+, geralmente em um bloco com `//{{AFX_DATA_INIT` e comentários de `//}}AFX_DATA_INIT` .  
  
 `CWnd::UpdateData` é a operação que faz a inicialização e o tratamento de erros em torno da chamada para `DoDataExchange`.  
  
 Você pode chamar `CWnd::UpdateData` a qualquer momento para executar troca de dados e a validação.  `UpdateData`\(TRUE\) é chamado por padrão no manipulador padrão e em `UpdateData`de `CDialog::OnOK` FALSE \(\) é chamado em `CDialog::OnInitDialog`padrão.  
  
 A rotina de DDV\_ deve vir logo após a rotina de DDX\_ para esse *campo*.  
  
## Como funciona?  
 Você não precisa entender o seguinte para usar dados da caixa de diálogo.  No entanto, compreender como esta funciona nos bastidores o ajudará a gravar seu próprio procedimento de troca ou de validação.  
  
 A função de membro de `DoDataExchange` é bem como a função de membro de `Serialize` \- é responsável para obter ou definir dados para um formulário\/desde externa \(nesse caso controles em uma caixa de diálogo\) desde\/até dados de membros na classe.  O parâmetro de `pDX` é o contexto para fazer troca de dados e é semelhante ao parâmetro de `CArchive` a `CObject::Serialize`.  `pDX` \(um objeto de `CDataExchange` \) tem um sinalizador de direção bem como `CArchive` tem um sinalizador de direção:  
  
-   Se **\!m\_bSaveAndValidate**, carrega o estado dos dados em controles.  
  
-   Se `m_bSaveAndValidate`, defina o estado dos dados dos controles.  
  
 A validação ocorre apenas quando `m_bSaveAndValidate` é definido.  O valor de `m_bSaveAndValidate` é determinado pelo parâmetro de BOOL a `CWnd::UpdateData`.  
  
 Há outros três membros interessantes de `CDataExchange` :  
  
-   `m_pDlgWnd`: A janela \(normalmente uma caixa de diálogo\) que contém os controles.  Este é impedir que os chamadores das funções de DDX\_ globais e de DDV\_ tenham que transmitir “ou” para cada rotina de DDX\/DDV.  
  
-   `PrepareCtrl`, e `PrepareEditCtrl`: Prepara um controle da caixa de diálogo para troca de dados.  Armazena esse identificador de controle para definir o foco se a validação falhar.  `PrepareCtrl` é usado para controles de nonedit e `PrepareEditCtrl` é usado para controles de edição.  
  
-   **Falha**: Chamado depois de ter colocado acima uma caixa de mensagem de alerta do usuário ao evento de entrada.  Esta rotina restaurará o foco para o controle o último \(a última chamada para `PrepareCtrl`\/`PrepareEditCtrl`\) e gerará uma exceção.  Essa função de membro pode ser chamada de rotinas de DDX\_ e de DDV\_.  
  
## Extensões de usuário  
 Há várias maneiras de estender o mecanismo de DDX\/DDV opção.  Você pode:  
  
-   Adicionar novos tipos de dados.  
  
    ```  
    CTime  
    ```  
  
-   Adicionar novos procedimentos de troca \(DDX\_???\).  
  
    ```  
    void PASCAL DDX_Time(CDataExchange* pDX, int nIDC, CTime& tm);  
    ```  
  
-   Adicionar novos procedimentos de validação \(DDV\_???\).  
  
    ```  
    void PASCAL DDV_TimeFuture(CDataExchange* pDX, CTime tm, BOOL bFuture);  
    // make sure time is in the future or past  
    ```  
  
-   Passe expressões arbitrárias a procedimentos de validação.  
  
    ```  
    DDV_MinMax(pDX, age, 0, m_maxAge);  
    ```  
  
    > [!NOTE]
    >  Tais expressões arbitrárias não podem ser editadas por ClassWizard e não devem ser movidas como consequência fora dos comentários especiais de formato \(\/{{AFX\_DATA\_MAP CMyClass \(\)\).  
  
 Faça com que a função de membro de **DoDialogExchange** incluir conditionals ou todas as outras instruções válidas C\+\+ com chamadas de função mistas e de troca de validação.  
  
```  
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
>  Como mostrado acima, esse código não pode ser editado por ClassWizard e só deve ser usado fora dos comentários especiais de formato.  
  
## Suporte de ClassWizard  
 ClassWizard suporte a um subconjunto das personalizações de DDX\/DDV permitindo que você integre suas próprias rotinas de DDX\_ e de DDV\_ na interface de usuário de ClassWizard.  Custo de fazer isso é útil somente se você planeja reutilizar os detalhes DDX e as rotinas de DDV em um projeto ou em muitos projetos.  
  
 Para fazer isso, as entradas especiais são feitas em DDX.CLW \(versões anteriores do Visual C\+\+ essas informações armazenadas em APSTUDIO.INI\) ou no arquivo de .CLW de seu projeto.  As entradas especiais podem ser inseridas na seção de informações \[\] geral do arquivo de .CLW de seu projeto ou na seção de ExtraDDX \[\] do arquivo de DDX.CLW em \\ arquivos de programas \\ Microsoft Visual Studio \\ Visual C\+\+ o diretório \\ bin.  Você pode precisar criar o arquivo de DDX.CLW se ainda não existir.  Se você planeja usar as rotinas personalizadas DDX\_\/DDV\_ apenas em um determinado projeto, adicione as entradas na seção de informações \[\] geral do arquivo de projeto .CLW em vez disso.  Se você planeja usar as rotinas em muitos projetos, adicione as entradas na seção de ExtraDDX \[\] de DDX.CLW.  
  
 O formato geral de cada uma dessas entradas especiais é:  
  
```  
ExtraDDXCount=n  
```  
  
 onde n é o número de ExtraDDX? linhas a seguir  
  
```  
ExtraDDX?=<keys>;<vb-keys>; <prompt>; <type>; <initValue>; <DDX_Proc>  
[;<DDV_Proc>; <prompt1>; <arg1>; [<prompt2>; <fmt2>]]  
```  
  
 onde? é um número de 1 a indicação de que em DDX na lista que está sendo definida.  
  
 Cada campo é limitado pelo; “” caractere.  Os campos e sua finalidade são descritos abaixo.  
  
 \<chaves\>  
 \= a lista de caracteres únicos que indicam que a caixa de diálogo controla esse tipo de variável é permitida.  
  
 E \= edição  
  
 2.0 \= C caixa de seleção de dois estado  
  
 c \= caixa de seleção tridimensionais de estado  
  
 R \= primeiro botão de opção em um grupo  
  
 L \= caixa de listagem não classificada  
  
 l \= classificou a caixa de listagem  
  
 M \= caixa de combinação \(com item de edição\)  
  
 N \= lista suspensa não classificada  
  
 n \= classificou a lista suspensa  
  
 1 \= se a inserção de DDX é adicionada ao início da lista \(opção é adicionar à parte final\) que este é usado normalmente para as rotinas de DDX que transferem a propriedade do controle “”.  
  
 \<VB\-chaves\>  
 Esse campo é usado somente no produto de 16 bits para controles de VBX \(os controles de VBX não têm suporte no produto de 32 bits\)  
  
 \<aviso\>  
 Cadeia de caracteres a ser colocado na caixa de combinação da propriedade \(nenhuma citação\)  
  
 \<tipo\>  
 Escolha o identificador do tipo emita\-se no arquivo de cabeçalho.  Em nosso exemplo anterior com DDX\_Time, seria definido como CTime.  
  
 \<VB\-chaves\>  
 Não usado nesta versão e sempre deve estar vazia  
  
 \<initValue\>  
 Valor inicial — 0 ou está em branco.  Se estiver em branco, nenhuma linha de inicialização será gravada em \/\/{{seção de AFX\_DATA\_INIT do arquivo de implementação.  Uma entrada em branco deve ser usada para os objetos C\+\+ \(como `CString`, `CTime`, e assim por diante\) que têm os construtores que garantem a inicialização correta.  
  
 \<DDX\_Proc\>  
 Único identificador para o procedimento de DDX\_.  O nome da função C\+\+ deve começar com “DDX\_”, mas não inclui “DDX\_” \<no identificador\> de DDX\_Proc.  No exemplo anterior, \<o\> identificador de DDX\_Proc seria tempo.  Quando ClassWizard grava a chamada de função para o arquivo de implementação em {{seção de AFX\_DATA\_MAP, anexará esse nome a DDX\_, assim chegando em DDX\_Time.  
  
 \<comentário\>  
 Comente a ser exibida na caixa de diálogo para a variável com esse DDX.  Coloque todo o texto do qual goste aqui, e fornecem geralmente algo que descreve a operação executada pelos pares de DDX\/DDV.  
  
 \<DDV\_Proc\>  
 A parte de DDV de entrada é opcional.  Nem todas as rotinas de DDX têm corresponder rotinas de DDV.  Geralmente, é mais conveniente incluir a fase de validação como uma parte integrante de transferência.  Frequentemente esse é o caso quando sua rotina de DDV não requer parâmetros, como ClassWizard não oferece suporte a rotinas de DDV sem nenhum parâmetro.  
  
 \<arg\>  
 Único identificador para o procedimento de DDV\_.  O nome da função C\+\+ deve começar com “DDV\_”, mas não inclui “DDX\_” \<no identificador\> de DDX\_Proc.  
  
 seguido por 1 ou 2 argumentos de DDV:  
  
 \<promptX\>  
 cadeia de caracteres para colocar acima do item edition \(com & para um acelerador\)  
  
 \<fmtX\>  
 caractere de formato para o tipo de, um de arg  
  
 d \= int  
  
 u \= não assinados  
  
 D \= long int \(ou seja, long\)  
  
 U \= tempo sem assinatura \(ou seja, DWORD\)  
  
 f \= float  
  
 F\- 2.0 \= double  
  
 s \= cadeia de caracteres  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)