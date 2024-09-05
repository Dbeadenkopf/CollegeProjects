void PokerHand::printCards(){
  Card extraCard[FIVE];
  for (int i = 0; i < FIVE; i++){
    if (m_cards[indx[i]].points() == m_cards[indx[i+1]].points()){
      extraCard[i] = m_cards[indx[i+1]];
    }
    else{
      m_cards[indx[i]].print();
    }
  }
}
// took extra card found an put into new class array pretty clitch
