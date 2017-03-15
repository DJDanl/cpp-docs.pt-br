---
title: "selectany | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "selectany_cpp"
  - "selectany"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], selectany"
  - "palavra-chave selectany __declspec"
ms.assetid: 9c353017-5a42-4f50-b741-bd13da1ce84d
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# selectany
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Informa ao compilador que o item de dados global declarado \(variável ou objeto\) é uma COMDAT aleatória \(uma função compactada\).  
  
## Sintaxe  
  
```  
  
__declspec( selectany ) declarator  
```  
  
## Comentários  
 No tempo de link, se várias definições de uma COMDAT forem consideradas, o vinculador escolherá uma e descartará o restante.  Se a opção do vinculador [\/OPT:REF](../build/reference/opt-optimizations.md) \(otimizações\) for selecionada, a eliminação de COMDAT ocorrerá para remover todos os itens de dados sem referência na saída do vinculador.  
  
 Os construtores e a atribuição pela função ou por métodos estáticos globais na declaração não criarão uma referência e não impedirão a eliminação de \/OPT:REF.  Os efeitos colaterais desse código não devem depender de quando não houver nenhuma outra referência aos dados.  
  
 Para objetos globais dinamicamente inicializados, `selectany` descartará também o código de inicialização de um objeto não referenciado.  
  
 Um item de dados global normalmente pode ser inicializado apenas uma vez em um projeto EXE ou DLL.  `selectany` pode ser usado na inicialização dos dados globais definidos por cabeçalhos quando o mesmo cabeçalho aparecer em mais de um arquivo de origem.  `selectany` está disponível nos compiladores C e C\+\+.  
  
> [!NOTE]
>  `selectany` só pode ser aplicado à inicialização real dos itens de dados globais que podem ser vistos externamente.  
  
## Exemplo  
 Este código mostra como usar o atributo `selectany`.  
  
```  
//Correct - x1 is initialized and externally visible   
__declspec(selectany) int x1=1;  
  
//Incorrect - const is by default static in C++, so   
//x2 is not visible externally (This is OK in C, since  
//const is not by default static in C)  
const __declspec(selectany) int x2 =2;  
  
//Correct - x3 is extern const, so externally visible  
extern const __declspec(selectany) int x3=3;  
  
//Correct - x4 is extern const, so it is externally visible  
extern const int x4;  
const __declspec(selectany) int x4=4;  
  
//Incorrect - __declspec(selectany) is applied to the uninitialized  
//declaration of x5  
extern __declspec(selectany) int x5;  
  
// OK: dynamic initialization of global object  
class X {  
public:  
X(int i){i++;};  
int i;  
};  
  
__declspec(selectany) X x(1);  
```  
  
## Exemplo  
 Este código mostra como usar o atributo `selectany` para assegurar a dobra de dados COMDAT quando você usar também a opção de vinculador [\/OPT:ICF](../build/reference/opt-optimizations.md).  Os dados devem ser marcados com `selectany` e ser colocados em uma seção **const** \(somente leitura\).  Você deve especificar explicitamente a seção somente leitura.  
  
```  
// selectany2.cpp  
// in the following lines, const marks the variables as read only  
__declspec(selectany) extern const int ix = 5;  
__declspec(selectany) extern const int jx = 5;  
int main() {  
   int ij;  
   ij = ix + jx;  
}  
```  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)